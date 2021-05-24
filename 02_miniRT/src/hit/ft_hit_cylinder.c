/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:08:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 11:37:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

static t_bool		ft_hit_cylinder_in_height(t_cylinder *cy, t_ray *ray,
																double root)
{
	double		height;

	height = ft_vdot(cy->axis,
					ft_vminus(ft_ray_at(ray, root), cy->center_bottom));
	return ((0 <= height) && (height <= cy->height));
}

static void			ft_discriminant(t_var_cylinder *v, t_cylinder *cy,
																t_ray *ray)
{
	v->v = ray->dir;
	v->w = ft_vminus(ray->org, cy->center_bottom);
	v->h = cy->axis;
	v->a = ft_vdot(v->v, v->v) - pow(ft_vdot(v->v, v->h), 2);
	v->half_b = ft_vdot(v->v, v->w) - ft_vdot(v->v, v->h) * ft_vdot(v->w, v->h);
	v->c = ft_vdot(v->w, v->w) - pow(ft_vdot(v->w, v->h), 2)
														- pow(cy->radius, 2);
	v->discriminant = v->half_b * v->half_b - v->a * v->c;
}

t_bool				ft_hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_rec *rec)
{
	t_var_cylinder	v;

	ft_discriminant(&v, cy, ray);
	if (v.discriminant < 0)
		return (false);
	v.sqrtd = sqrt(v.discriminant);
	v.root = (-1 * v.half_b - v.sqrtd) / v.a;
	if (!ft_hit_cylinder_in_height(cy, ray, v.root) ||
									v.root < rec->t_min || rec->t_max < v.root)
	{
		v.root = (-1 * v.half_b + v.sqrtd) / v.a;
		if (v.root < rec->t_min || rec->t_max < v.root)
			return (false);
	}
	if (!ft_hit_cylinder_in_height(cy, ray, v.root))
		return (false);
	rec->t = v.root;
	rec->p = ft_ray_at(ray, v.root);
	rec->normal = ft_vunit(ft_vminus(rec->p, ft_vplus(cy->center_bottom,
					ft_vscalar(cy->axis,
					ft_vdot(ft_vminus(rec->p, cy->center_bottom), cy->axis)))));
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = cy->color;
	return (true);
}
