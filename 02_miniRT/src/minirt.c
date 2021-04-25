/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/26 06:54:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "scene.h"
#include "color.h"
#include "vector.h"
#include "ray.h"
#include "object.h"

t_vec3		ft_ray_at(t_ray ray, double t)
{
	ray.org = V_PLUS(ray.org, V_SCALAR(ray.dir, t));
	return (ray.org);
}

double		ft_hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = V_MINUS(ray->org, sp->center);
	a = V_DOT(ray->dir, ray->dir);
	half_b = V_DOT(ray->dir, oc);
	c = V_DOT(oc, oc) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-1 * half_b - sqrt(discriminant)) / a);
}

t_color		ft_ray_to_color(t_ray ray, t_sphere *sp)
{
	t_vec3		unit_direction;
	t_vec3		n;
	double		t;
	t_color		rtn;

	t = ft_hit_sphere(sp, &ray);
	if (t > 0.0)
	{
		n = V_UNIT(V_MINUS(ft_ray_at(ray, t), sp->center));
		return (V_SCALAR(V_SET(n.x + 1, n.y + 1, n.z + 1), 0.5));
	}
	unit_direction = V_UNIT(ray.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	rtn = V_PLUS(V_SCALAR(V_SET(1.0, 1.0, 1.0), (1.0 - t)), V_SCALAR(V_SET(0.5, 0.7, 1.0), t));
	return (rtn);
}

void		ft_render(t_ctrl *ctrl)
{
	char		*data;
	int			y, x;

	//camera
	double		viewport_height = 2.0;
	double		viewport_width = ctrl->scene->aspect_ratio * viewport_height;
	double		focal_length = 1.0;
	double		u, v;

	t_point3	origin;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	upper_left_corner;
	t_ray		ray;
	t_color		color;

	//sphere
	t_sphere	sp;
	sp.center = V_SET(0, 0, -1);
	sp.radius = 0.5;

	origin = V_SET(0, 0, 0);
	horizontal = V_SET(viewport_width, 0, 0);
	vertical = V_SET(0, viewport_height, 0);
	upper_left_corner = V_MINUS(V_PLUS(V_MINUS(origin, V_SCALAR(horizontal, 0.5)), V_SCALAR(vertical, 0.5)), V_SET(0, 0, focal_length));
	
	y = ctrl->scene->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ctrl->scene->width)
		{
			if ((x == ctrl->scene->width / 2) && (y == ctrl->scene->height / 2))
			{
				ray.org.x = 1;
			}
			u = (double)x / (ctrl->scene->width - 1);
			v = (double)y / (ctrl->scene->height - 1);
			ray.org = origin;
			ray.dir = V_MINUS(V_MINUS(V_PLUS(upper_left_corner, V_SCALAR(horizontal, u)),
						V_SCALAR(vertical, v)), origin);
			color = ft_ray_to_color(ray, &sp);
			data = ctrl->img.data + (y * ctrl->img.size_line + x * (ctrl->img.bit_per_pixel / 8));
			*(unsigned int *)data = ft_rgb_to_data(color);
			x++;
		}
		y--;
	}
}

void		ft_minirt(t_ctrl *ctrl)
{
	ctrl->mlx_ptr = mlx_init();
	ctrl->win_ptr = mlx_new_window(ctrl->mlx_ptr, ctrl->scene->width, ctrl->scene->height, "miniRT");
	ctrl->img.img_ptr = mlx_new_image(ctrl->mlx_ptr, ctrl->scene->width, ctrl->scene->height);
	ctrl->img.data = mlx_get_data_addr(ctrl->img.img_ptr, &ctrl->img.bit_per_pixel,
					&ctrl->img.size_line, &ctrl->img.endian);
	ft_render(ctrl);
	mlx_put_image_to_window(ctrl->mlx_ptr, ctrl->win_ptr, ctrl->img.img_ptr, 0, 0);
	mlx_loop(ctrl->mlx_ptr);
}

int			main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	ctrl.scene = (t_scene *)malloc(sizeof(t_scene));
	if (argc == 2 && ft_is_endstr(argv[1], ".rt"))
	{
		ft_read_rt(&ctrl, argv[2]);
		ft_minirt(&ctrl);
	}
	// else if (argc == 3)
	// ft_save_bmp();
	// else
	// ft_error_handler();
	return (0);
}