/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:48:42 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 15:59:07 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "object.h"
#include "hit.h"

t_bool		ft_render(t_ctrl *c)
{
	t_var_render	v;

	v.camera = (t_camera *)ft_return_object(c->scene->camera_list,
											c->scene->idx_c);
	v.y = 0;
	while (v.y < c->scene->canv.height)
	{
		v.x = 0;
		while (v.x < c->scene->canv.width)
		{
			v.ray = ft_ray_init(c, v.camera, (double)v.x, (double)v.y);
			v.color = ft_ray_to_color(v.ray, c);
			v.data = c->img.data + (v.y * c->img.size_line +
									v.x * (c->img.bit_per_pixel / 8));
			*(unsigned int *)v.data = ft_rgb_to_data(v.color);
			v.x++;
		}
		v.y++;
	}
	return (success);
}
