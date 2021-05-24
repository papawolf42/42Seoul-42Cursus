/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_determine_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:10:38 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 12:03:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_front		ft_ray_determine_front(t_ray *ray, t_hit_rec *rec)
{
	double		dot;

	dot = ft_vdot(ray->dir, rec->normal);
	if (dot < 0)
		return (front);
	else
	{
		rec->normal = ft_vscalar(rec->normal, -1);
		return (back);
	}
}
