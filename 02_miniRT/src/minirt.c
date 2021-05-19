/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 22:51:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "color.h"
#include "vector.h"
#include "ray.h"
#include "alias.h"
#include "error.h"
#include "parse.h"
#include "exit.h"
#include "object.h"
#include "event.h"

t_vec3		ft_ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = V_PLUS(ray->org, V_SCALAR(ray->dir, t));
	return (at);
}

t_front		ft_determine_front(t_ray *ray, t_hit_rec *rec)
{
	double		dot;
	dot = V_DOT(ray->dir, rec->normal);
	if (dot < 0)
	{
		return (front);
	}
	else
	{
		rec->normal = V_SCALAR(rec->normal, -1);
		return (back);
	}
}

t_vec3		ft_get_point(t_point3 org, t_vec3 dir, double t)
{
	return (V_PLUS(org, V_SCALAR(dir, t)));
}

t_bool		ft_hit_triangle(t_triangle *tr, t_ray *ray, t_hit_rec *rec)
{
	double	proj_unit;
	double	proj_len;
	double	root;
	t_vec3	p;

	t_vec3	na;
	t_vec3	nb;
	t_vec3	nc;

	proj_unit = V_DOT(ray->dir, tr->normal);
	if (fabs(proj_unit) < 0.0001)
		return (false);
	proj_len = V_DOT(V_MINUS(tr->a, ray->org), tr->normal);
	root = proj_len / proj_unit;
	if (root < rec->t_min || rec->t_max < root)
		return (false);
	p = ft_ray_at(ray, root);

	na = V_CROSS(V_MINUS(p, tr->a), tr->ab);
	nb = V_CROSS(V_MINUS(p, tr->b), tr->bc);
	nc = V_CROSS(V_MINUS(p, tr->c), tr->ca);

	if (V_DOT(na, nb) < 0 || V_DOT(nb, nc) < 0 || V_DOT(nc, na) < 0)
		return (false);
	rec->t = root;
	rec->p = p;
	rec->normal = tr->normal;
	rec->front_face = ft_determine_front(ray, rec);
	rec->color = tr->color;
	return (true);
}

t_bool		ft_hit_cylinder_in_height(t_cylinder *cy, t_ray *ray, double root)
{
	double		height;

	height = V_DOT(cy->axis, V_MINUS(ft_ray_at(ray, root), cy->center_bottom));
	return ((0 <= height) && (height <= cy->height));
}

t_bool		ft_hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_rec *rec)
{
	t_vec3		v;
	t_vec3		w;
	t_vec3		h;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;// 판별식
	double		root;// 근
	double		sqrtd;// 근의 제곱근

	v = ray->dir;
	w = V_MINUS(ray->org, cy->center_bottom);
	h = cy->axis;

	a = V_DOT(v, v) - pow(V_DOT(v, h), 2);
	half_b = V_DOT(v, w) - V_DOT(v, h) * V_DOT(w, h);
	c = V_DOT(w, w) - pow(V_DOT(w, h), 2) - pow(cy->radius, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (false);
	sqrtd = sqrt(discriminant);
	root = (-1 * half_b - sqrtd) / a;
	if (!ft_hit_cylinder_in_height(cy, ray, root) || root < rec->t_min || rec->t_max < root)
	{
		root = (-1 * half_b + sqrtd) / a;
		if (root < rec->t_min || rec->t_max < root)
			return (false);
	}
	if (!ft_hit_cylinder_in_height(cy, ray, root))
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	
	rec->normal = V_UNIT(V_MINUS(rec->p, V_PLUS(cy->center_bottom, V_SCALAR(cy->axis, V_DOT(V_MINUS(rec->p, cy->center_bottom), cy->axis)))));
	rec->front_face = ft_determine_front(ray, rec);
	rec->color = cy->color;
	return (true);
}

t_bool		ft_hit_square(t_square *sq, t_ray *ray, t_hit_rec *rec)
{
	double		proj_unit;
	double		proj_len;
	double		root;
	t_point3	point_t;
	t_vec3		diff;

	proj_unit = V_DOT(ray->dir, sq->normal);
	if (fabs(proj_unit) < 0.0001)
		return (false);
	proj_len = V_DOT(V_MINUS(sq->center, ray->org), sq->normal);
	root = proj_len / proj_unit;
	if (root < rec->t_min || rec->t_max < root)
		return (false);
	point_t = ft_ray_at(ray, root);
	diff = V_MINUS(point_t, sq->center);
	if (fabs(V_DOT(sq->span_a, diff)) > sq->side_len / 2 || fabs(V_DOT(sq->span_b, diff)) > sq->side_len / 2)
		return (false);
	rec->t = root;
	rec->p = point_t;
	rec->normal = sq->normal;
	rec->front_face = ft_determine_front(ray, rec);
	rec->color = sq->color;
	return (true);
}

t_bool		ft_hit_plane(t_plane *pl, t_ray *ray, t_hit_rec *rec)
{
	double	proj_unit;
	double	proj_len;
	double	root;

	proj_unit = V_DOT(ray->dir, pl->normal);
	if (fabs(proj_unit) < 0.0001)
		return (false);
	proj_len = V_DOT(V_MINUS(pl->point, ray->org), pl->normal);
	root = proj_len / proj_unit;
	if (root < rec->t_min || rec->t_max < root)
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = pl->normal;
	rec->front_face = ft_determine_front(ray, rec);
	rec->color = pl->color;
	return (true);
}

t_bool		ft_hit_sphere(t_sphere *sp, t_ray *ray, t_hit_rec *rec)
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;// 판별식
	double		root;// 근
	double		sqrtd;// 근의 제곱근

	oc = V_MINUS(ray->org, sp->center);
	a = V_DOT(ray->dir, ray->dir);
	half_b = V_DOT(ray->dir, oc);
	c = V_DOT(oc, oc) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (false);
	sqrtd = sqrt(discriminant);
	root = (-1 * half_b - sqrtd) / a;
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (-1 * half_b + sqrtd) / a;
		if (root < rec->t_min || rec->t_max < root)
			return (false);
	}
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = V_SCALAR(V_MINUS(rec->p, sp->center), (double)1 / sp->radius);
	rec->front_face = ft_determine_front(ray, rec);
	rec->color = sp->color;
	return (true);
}

t_bool		ft_hit_obj(t_object_list *obj, t_ray *ray,t_hit_rec *rec)
{
	t_bool		bool_hit;

	bool_hit = false;
	if (obj->type == sp)
		bool_hit = ft_hit_sphere(obj->object, ray, rec);
	if (obj->type == pl)
		bool_hit = ft_hit_plane(obj->object, ray, rec);
	if (obj->type == sq)
		bool_hit = ft_hit_square(obj->object, ray, rec);
	if (obj->type == cy)
		bool_hit = ft_hit_cylinder(obj->object, ray, rec);
	if (obj->type == tr)
		bool_hit = ft_hit_triangle(obj->object, ray, rec);
	return (bool_hit);
}

t_bool		ft_hit(t_object_list *obj, t_ray *ray, t_hit_rec *rec)
{
	t_bool		bool_hit;

	bool_hit = false;
	while (obj)
	{
		if (ft_hit_obj(obj, ray, rec))
		{
			bool_hit = true;
			rec->t_max = rec->t;
		}
		obj = obj->next;
	}
	return (bool_hit);
}

t_bool		ft_is_not_shadow(t_object_list *obj, t_light *light, t_hit_rec *rec)
{
	t_ray		back_track_ray;
	t_hit_rec	rec_light;
	
	back_track_ray.org = rec->p;
	back_track_ray.dir = V_MINUS(light->p, rec->p);

	rec_light.t_min = M_EPSILON;
	rec_light.t_max = 1;
	while (obj)
	{
		if (ft_hit_obj(obj, &back_track_ray, &rec_light))
		{
			return (false);
		}
		obj = obj->next;
	}
	return (true);
}

t_color		ft_phong_color_compute(t_light *light, t_ray *ray, t_hit_rec *rec, t_ambient a)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		light_intensity;

	t_vec3		to_light;
	t_vec3		to_view;
	t_vec3		reflect;

	double		kd;
	double		ks;
	double		ksn;

	double		attenuation_radius;
	double		attenuation_distance;
	double		radius_attenuation;
	double		distance;

	radius_attenuation = 4;
	distance = V_LEN(V_MINUS(light->p, rec->p)) / 3;
	if (radius_attenuation < distance)
		return (V_COLOR(0, 0, 0));

	to_light = V_UNIT(V_MINUS(light->p, rec->p));
	to_view = V_UNIT(V_MINUS(ray->org, rec->p));
	reflect = V_UNIT(V_REFLECT(V_SCALAR(to_light, -1), rec->normal));

	kd = ft_max(V_DOT(V_UNIT(rec->normal), to_light), 0.0);
	ks = 0.3;
	ksn = 32;
	ambient = V_SCALAR(a.color, a.ratio);
	diffuse = V_SCALAR(light->color, kd);
	specular = V_SCALAR(light->color, ks * pow(ft_max(V_DOT(reflect, to_view), 0.0), ksn));
	// attenuation_radius = pow(ft_saturate(1 - pow(distance / radius_attenuation, 4)), 2);
	attenuation_radius = 1;
	// attenuation_distance = 1 / (pow(distance, 2) + 1);
	attenuation_distance = 1;
	light_intensity = V_SCALAR(V_PLUS(diffuse, specular), light->ratio);
	// return (V_PLUS(ambient, V_SCALAR(light_intensity, attenuation_distance * attenuation_radius)));
	return (V_PLUS(ambient, V_MULT(light->color, light_intensity)));
}

t_color		ft_phong_color(t_scene *s, t_ray *ray, t_hit_rec *rec)
{
	t_color			light_stack;
	t_object_list	*lights;

	// ray->org = ray->org;
	lights = s->light_list;
	light_stack = V_COLOR(0, 0, 0);
	// light_stack = V_COLOR(1, 1, 1);
	while (lights)
	{
		if (ft_is_not_shadow(s->object_list, lights->object, rec))
			light_stack = V_PLUS(light_stack, ft_phong_color_compute(lights->object, ray, rec, s->ambient));
		lights = lights->next;
	}
	return (V_MIN(V_MULT(light_stack, rec->color), V_SET(0.999, 0.999, 0.999)));
}

t_color		ft_ray_to_color(t_ray ray, t_ctrl *c)
{
	t_vec3		unit_direction;
	double		t;
	t_hit_rec	rec;

	rec.t_min = M_EPSILON;
	rec.t_max = M_INFINITY;

	if (ft_hit(c->scene->object_list, &ray, &rec))
	{
		return (ft_phong_color(c->scene, &ray, &rec));
	}
	else
	{
		unit_direction = V_UNIT(ray.dir);
		t = 0.5 * (unit_direction.y + 1.0);
		return (V_PLUS(V_SCALAR(V_SET(1.0, 1.0, 1.0), (1.0 - t)), V_SCALAR(V_SET(0.5, 0.7, 1.0), t)));
	}
}

t_ray		ft_ray_init(t_canvas *canv, t_camera *cam, int x, int y)
{
	t_ray		ray;
	t_point3	screen;

	screen.x = (2 * ((x + 0.5) / canv->width) - 1);
	screen.x *= FISH_EYE_INDEX;// FISH_EYE
	screen.y = (2 * ((canv->height - y + 0.5) / canv->height) - 1);
	screen.y *= FISH_EYE_INDEX;// FISH_EYE
	screen.z = -1;
	screen.z *= sqrt(1 - screen.x * screen.x - screen.y * screen.y);// FISH_EYE
	screen.x *= cam->fov * canv->aspect_ratio;
	screen.y *= cam->fov;
	cam->mat_c2w = ft_getmat_c2w(cam, AXIS_UP);
	ray.org = cam->origin;
	ray.dir = V_MINUS(ft_linear_transform(cam->mat_c2w, screen), ray.org);
	return (ray);
}

t_bool		ft_render(t_ctrl *c)
{
	char		*data;
	int			y, x;
	t_ray		ray;
	t_color		color;
	t_camera	*cam;
	
	cam = (t_camera *)ft_return_object(c->scene->camera_list, c->scene->idx_c);
	y = c->scene->canv.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->scene->canv.width)
		{
			if ((x == 400) && (y == 250))
			{
				ray.org.x = 1;
			}
			ray = ft_ray_init(&c->scene->canv, cam, x, y);
			color = ft_ray_to_color(ray, c);
			data = c->img.data + (y * c->img.size_line + x * (c->img.bit_per_pixel / 8));
			*(unsigned int *)data = ft_rgb_to_data(color);
			x++;
		}
		y--;
	}
	return (success);
}

int		ft_get_position_clicked(int click, int x, int y, t_scene *s)
{
	(void)click;
	s->canv.height = s->canv.height;// meaningless
	printf("x:%d, y:%d\n", x, y);
	return (0);
}

void		ft_minirt(t_ctrl *ctrl)
{
	ctrl->mlx_ptr = mlx_init();
	ctrl->win_ptr = mlx_new_window(ctrl->mlx_ptr, ctrl->scene->canv.width, ctrl->scene->canv.height, "miniRT");
	ctrl->img.img_ptr = mlx_new_image(ctrl->mlx_ptr, ctrl->scene->canv.width, ctrl->scene->canv.height);
	ctrl->img.data = mlx_get_data_addr(ctrl->img.img_ptr, &ctrl->img.bit_per_pixel,
					&ctrl->img.size_line, &ctrl->img.endian);
	ft_render(ctrl);
	mlx_put_image_to_window(ctrl->mlx_ptr, ctrl->win_ptr, ctrl->img.img_ptr, 0, 0);
	mlx_hook(ctrl->win_ptr, EVENT_BUTTONPRESS, 1L << 0, ft_get_position_clicked, ctrl->scene);
	ft_init_hook(ctrl);
	// mlx_loop(ctrl->mlx_ptr);
}

int			main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	ft_bzero(&ctrl, sizeof(ctrl));
	ctrl.mode = 'C';
	if (argc < 2 || 3 < argc)
		return (ft_err_msg(ERR_WRONG_NUMBERS_ARG));
	if (ft_is_endstr(argv[1], ".rt") == fail)
		return (ft_err_msg(ERR_2ND_ARG_NOT_END_RT) == fail);
	if (ft_parse_rt(&ctrl, argv[1]))
		return (ft_exit_minirt(&ctrl));
	if (argc == 2)
		ft_minirt(&ctrl);
	else if (argc == 3 && ft_strncmp(argv[3], "--save", 8) == 0)
		// ft_save_bmp();
	return (0);
}
