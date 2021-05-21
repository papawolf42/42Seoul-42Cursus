/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:17:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 22:04:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "minirt.h"
#include "struct.h"
#include "object.h"

int				ft_select_object(t_ctrl *c, int x, int y)
{
	t_ray		ray;
	t_camera	*cam;
	t_hit_rec	rec;

	cam = (t_camera *)ft_return_object(c->scene->camera_list, c->scene->idx_c);
	ray = ft_ray_init(&c->scene->canv, cam, x, y);
	rec.t_min = M_EPSILON;
	rec.t_max = M_INFINITY;
	if (ft_hit(c->scene->object_list, &ray, &rec) == false)
	{
		c->mode = 'C';
		return (false);
	}
	c->object_selected = rec.object_list;
	c->mode = 'O';
	return (true);
}
