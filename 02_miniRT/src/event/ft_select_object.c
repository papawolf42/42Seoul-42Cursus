/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:17:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 09:21:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "minirt.h"
#include "struct.h"
#include "object.h"
#include "hit.h"
#include "event.h"

int				ft_select_object(t_ctrl *c, int x, int y)
{
	t_ray		ray;
	t_camera	*cam;
	t_hit_rec	rec;

	cam = (t_camera *)ft_return_object(c->scene->camera_list, c->scene->idx_c);
	ray = ft_ray_init(c, cam, x, y);
	ft_bzero(&rec, sizeof(rec));
	rec.t_min = M_EPSILON;
	rec.t_max = M_INFINITY;
	if (ft_hit(c->scene->object_list, &ray, &rec) == false)
	{
		if (c->mode == 'c')
			c->mode = 'C';
		else if (c->mode == 'l')
			c->mode = 'L';
	}
	c->object_selected = rec.object_list;
	if (rec.object_list == NULL)
		c->object_selected = ft_return_object(c->scene->object_list,
														c->scene->idx_o);
	if (c->mode == 'C')
		c->mode = 'c';
	else if (c->mode == 'L')
		c->mode = 'l';
	return (true);
}
