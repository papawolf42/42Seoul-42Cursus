/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_to_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:52:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 22:19:18 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

t_color		ft_ray_to_color(t_ray ray, t_ctrl *c)
{
	t_vec3		unit_direction;
	double		t;
	t_hit_rec	rec;

	rec.t_min = M_EPSILON;
	rec.t_max = M_INFINITY;

	if (ft_hit(c->scene->object_list, &ray, &rec))
	{
		return (ft_phong_color(c->scene, &ray, &rec));
	}
	else
	{
		unit_direction = V_UNIT(ray.dir);
		t = 0.5 * (unit_direction.y + 1.0);
		return (V_PLUS(V_SCALAR(V_SET(1.0, 1.0, 1.0), (1.0 - t)), V_SCALAR(V_SET(0.5, 0.7, 1.0), t)));
	}
}