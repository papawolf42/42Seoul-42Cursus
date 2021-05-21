/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:07:29 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 22:10:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

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
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = sq->color;
	return (true);
}
