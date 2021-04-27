/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/28 05:50:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "color.h"
#include "vector.h"
#include "ray.h"
#include "alias.h"

t_vec3		ft_ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = V_PLUS(ray->org, V_SCALAR(ray->dir, t));
	return (at);
}

t_bool		ft_determine_front(t_ray *ray, t_hit_rec *rec)
{
	double		dot;
	dot = V_DOT(ray->dir, rec->normal);
	if (dot < 0)
	{
		return (true);
	}
	else
	{
		rec->p = V_SCALAR(rec->p, -1);
		return (false);
	}
}

double		ft_hit_sphere(t_sphere *sp, t_ray *ray, t_hit_rec *rec)
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
	return (true);
}

t_bool		ft_hit_obj(t_object_list *obj, t_ray *ray,t_hit_rec *rec)
{
	t_bool		bool_hit;

	bool_hit = false;
	if (obj->type == sp)
		bool_hit = ft_hit_sphere(obj->object, ray, rec);
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

t_color		ft_ray_to_color(t_ray ray, t_ctrl *c)
{
	t_vec3		unit_direction;
	double		t;
	t_hit_rec	rec;

	rec.t_min = 0;
	rec.t_max = M_INFINITY;

	if (ft_hit(c->scene->object_list, &ray, &rec))
	{
		return (V_SCALAR(V_SET(rec.normal.x + 1, rec.normal.y + 1, rec.normal.z + 1), 0.5));
	}
	else
	{
		unit_direction = V_UNIT(ray.dir);
		t = 0.5 * (unit_direction.y + 1.0);
		return (V_PLUS(V_SCALAR(V_SET(1.0, 1.0, 1.0), (1.0 - t)), V_SCALAR(V_SET(0.5, 0.7, 1.0), t)));
	}
}

void		ft_render(t_ctrl *c)
{
	char		*data;
	int			y, x;
	double		u, v;
	t_ray		ray;
	t_color		color;
	
	y = c->scene->canv.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->scene->canv.width)
		{
			if ((x == (int)(c->scene->canv.width * 0.68)) && (y == (int)(c->scene->canv.height * 0.5)))
			{
				ray.org.x = 1;
			}
			u = (double)x / (c->scene->canv.width - 1);
			v = (double)y / (c->scene->canv.height - 1);
			ray.org = c->scene->camera_list->camera->origin;
			ray.dir = V_MINUS(V_MINUS(V_PLUS(c->scene->camera_list->camera->left_top,
						V_SCALAR(c->scene->camera_list->camera->horizontal, u)),
						V_SCALAR(c->scene->camera_list->camera->vertical, v)),
						c->scene->camera_list->camera->origin);
			color = ft_ray_to_color(ray, c);
			data = c->img.data + (y * c->img.size_line + x * (c->img.bit_per_pixel / 8));
			*(unsigned int *)data = ft_rgb_to_data(color);
			x++;
		}
		y--;
	}
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
	mlx_loop(ctrl->mlx_ptr);
}

int			main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	if (2 <= argc && argc <= 3)
	{
		if (ft_is_endstr(argv[1], ".rt"))
		{
			ft_parse_rt(&ctrl, argv[2]);
			if (argc == 2)
				ft_minirt(&ctrl);
			// else if (argc == 3 && ft_strncmp(argv[3], "--save", 7) == 0)
				// ft_save_bmp();
		}
		// else
			// ft_error_handler(ERR_WRONG_ARG);
	}
	// else
	// {
		//ft_error_handler(ERR_WRONG_ARG);
	// }
	return (0);
}