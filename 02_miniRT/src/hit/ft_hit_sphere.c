/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:04:07 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 22:10:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

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
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = sp->color;
	return (true);
}