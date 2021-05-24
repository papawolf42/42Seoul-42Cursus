/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_multi_thread.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:53:35 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "hit.h"
#include "struct.h"
#include "object.h"
#include "error.h"

static void	*ft_render_multi_thread_each(void *pth_data)
{
	t_pth_data		*d;
	t_ctrl			c;
	t_var_render	v;

	d = (t_pth_data *)pth_data;
	c = *d->ctrl;
	v.camera = (t_camera *)ft_return_object(c.scene->camera_list,
											c.scene->idx_c);
	v.y = d->ctrl->scene->canv.height - 1 - d->lane;
	while (v.y >= 0)
	{
		v.x = 0;
		while (v.x < d->ctrl->scene->canv.width)
		{
			v.ray = ft_ray_init(&c, v.camera, (double)v.x, (double)v.y);
			v.color = ft_ray_to_color(v.ray, &c);
			v.data = c.img.data + (v.y * c.img.size_line +
									v.x * (c.img.bit_per_pixel / 8));
			*(unsigned int *)v.data = ft_rgb_to_data(v.color);
			v.x++;
		}
		v.y -= d->count;
	}
	return (NULL);
}

t_bool		ft_render_multi_thread(t_ctrl *ctrl)
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
		if (pthread_create(&pthread[i], NULL, ft_render_multi_thread_each,
											(void *)&data[i]) < 0)
			return (ft_err_msg("pthread create failed"));
	}
	i = -1;
	while (++i < NUM_THREAD)
		pthread_join(pthread[i], NULL);
	return (success);
}
