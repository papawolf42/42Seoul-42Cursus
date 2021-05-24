/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:08:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 12:02:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

t_bool		ft_hit_triangle(t_triangle *tr, t_ray *ray, t_hit_rec *rec)
{
	t_var_triangle	v;

	v.proj_unit = ft_vdot(ray->dir, tr->normal);
	if (fabs(v.proj_unit) < 0.0001)
		return (false);
	v.proj_len = ft_vdot(ft_vminus(tr->a, ray->org), tr->normal);
	v.root = v.proj_len / v.proj_unit;
	if (v.root < rec->t_min || rec->t_max < v.root)
		return (false);
	v.p = ft_ray_at(ray, v.root);
	v.na = ft_vcross(ft_vminus(v.p, tr->a), tr->ab);
	v.nb = ft_vcross(ft_vminus(v.p, tr->b), tr->bc);
	v.nc = ft_vcross(ft_vminus(v.p, tr->c), tr->ca);
	if (ft_vdot(v.na, v.nb) < 0 || ft_vdot(v.nb, v.nc) < 0 ||
													ft_vdot(v.nc, v.na) < 0)
		return (false);
	rec->t = v.root;
	rec->p = v.p;
	rec->normal = tr->normal;
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = tr->color;
	return (true);
}
