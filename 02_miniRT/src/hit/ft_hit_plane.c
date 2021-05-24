/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:06:42 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 11:57:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

t_bool		ft_hit_plane(t_plane *pl, t_ray *ray, t_hit_rec *rec)
{
	double	proj_unit;
	double	proj_len;
	double	root;

	proj_unit = ft_vdot(ray->dir, pl->normal);
	if (fabs(proj_unit) < 0.0001)
		return (false);
	proj_len = ft_vdot(ft_vminus(pl->point, ray->org), pl->normal);
	root = proj_len / proj_unit;
	if (root < rec->t_min || rec->t_max < root)
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = pl->normal;
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = pl->color;
	return (true);
}
