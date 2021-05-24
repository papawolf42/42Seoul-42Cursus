/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:08:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 19:09:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "object.h"
#include "hit.h"
#include "color.h"
#include "minirt.h"

t_bool			ft_render_aa(t_ctrl *c)
{
	t_var_render	v;

	v.camera = (t_camera *)ft_return_object(c->scene->camera_list,
											c->scene->idx_c);
	v.y = 0;
	while (v.y <= SAMPLING * c->scene->canv.height)
	{
		v.x = 0;
		while (v.x <= SAMPLING * c->scene->canv.width)
		{
			v.ray = ft_ray_init_aa(c, v.camera,
							(double)v.x / SAMPLING, (double)v.y / SAMPLING);
			c->scene->data_aa[v.y * SAMPLING * c->scene->canv.width + v.x] =
													ft_ray_to_color(v.ray, c);
			v.x++;
		}
		v.y++;
	}
	ft_fill_data_aa(c);
	return (success);
}
