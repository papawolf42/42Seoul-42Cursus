/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:08:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 22:10:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

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
	rec->front_face = ft_ray_determine_front(ray, rec);
	rec->color = tr->color;
	return (true);
}
