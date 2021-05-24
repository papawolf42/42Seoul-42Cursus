/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_mt_aa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:07:45 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "hit.h"
#include "struct.h"
#include "object.h"
#include "color.h"
#include "minirt.h"
#include "error.h"

static void	*ft_render_multi_thread_each_aa(void *pth_data)
{
	t_pth_data		*d;
	t_ctrl			c;
	t_var_render	v;

	d = (t_pth_data *)pth_data;
	c = *d->ctrl;
	v.camera = (t_camera *)ft_return_object(c.scene->camera_list,
											c.scene->idx_c);
	v.y = SAMPLING * d->ctrl->scene->canv.height - 1 - d->lane;
	while (v.y >= 0)
	{
		v.x = 0;
		while (v.x < SAMPLING * d->ctrl->scene->canv.width)
		{
			v.ray = ft_ray_init_aa(&c, v.camera,
					(double)v.x / SAMPLING, (double)v.y / SAMPLING);
			c.scene->data_aa[v.y * SAMPLING * c.scene->canv.width + v.x] =
												ft_ray_to_color(v.ray, &c);
			v.x++;
		}
		v.y -= d->count;
	}
	ft_fill_data_aa(&c);
	return (NULL);
}

t_bool		ft_render_mt_aa(t_ctrl *ctrl)
{
	pthread_t		pthread[NUM_THREAD];
	t_pth_data		data[NUM_THREAD];
	int				i;

	i = -1;
	while (++i < NUM_THREAD)
	{
		data[i].count = NUM_THREAD;
		data[i].ctrl = ctrl;
	}
	i = -1;
	while (++i < NUM_THREAD)
	{
		data[i].lane = i;
		if (pthread_create(&pthread[i], NULL, ft_render_multi_thread_each_aa,
											(void *)&data[i]) < 0)
			return (ft_err_msg("pthread create failed"));
	}
	i = -1;
	while (++i < NUM_THREAD)
		pthread_join(pthread[i], NULL);
	return (success);
}
