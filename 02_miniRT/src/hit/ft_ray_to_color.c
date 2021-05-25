/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_to_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:52:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 08:50:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

t_color		ft_ray_to_color(t_ray ray, t_ctrl *c)
{
	t_hit_rec	rec;

	rec.t_min = M_EPSILON;
	rec.t_max = M_INFINITY;
	if (ft_hit(c->scene->object_list, &ray, &rec))
	{
		return (ft_phong_color(c->scene, &ray, &rec));
	}
	else
	{
		return (ft_vset(0, 0, 0));
	}
}
