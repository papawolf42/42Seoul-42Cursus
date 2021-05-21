/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:08:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 00:56:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

static t_bool		ft_hit_cylinder_in_height(t_cylinder *cy, t_ray *ray, double root)
{
	double		height;

	height = V_DOT(cy->axis, V_MINUS(ft_ray_at(ray, root), cy->center_bottom));
	return ((0 <= height) && (height <= cy->height));
}

t_bool				ft_hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_rec *rec)
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
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = cy->color;
	return (true);
}
