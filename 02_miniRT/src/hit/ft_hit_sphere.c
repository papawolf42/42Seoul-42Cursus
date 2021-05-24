/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:04:07 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 11:57:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

static t_bool	ft_root_sphere(double *root, t_sphere *sp, t_ray *ray,
															t_hit_rec *rec)
{
	t_var_sphere	v;

	v.oc = ft_vminus(ray->org, sp->center);
	v.a = ft_vdot(ray->dir, ray->dir);
	v.half_b = ft_vdot(ray->dir, v.oc);
	v.c = ft_vdot(v.oc, v.oc) - sp->radius * sp->radius;
	v.discriminant = v.half_b * v.half_b - v.a * v.c;
	if (v.discriminant < 0)
		return (false);
	v.sqrtd = sqrt(v.discriminant);
	*root = (-1 * v.half_b - v.sqrtd) / v.a;
	if (*root < rec->t_min || rec->t_max < *root)
	{
		*root = (-1 * v.half_b + v.sqrtd) / v.a;
		if (*root < rec->t_min || rec->t_max < *root)
			return (false);
	}
	return (true);
}

t_bool			ft_hit_sphere(t_sphere *sp, t_ray *ray, t_hit_rec *rec)
{
	double root;

	if (ft_root_sphere(&root, sp, ray, rec) == false)
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = ft_vscalar(ft_vminus(rec->p, sp->center), 1.0 / sp->radius);
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = sp->color;
	return (true);
}
