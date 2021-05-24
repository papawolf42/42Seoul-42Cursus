/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data_aa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:07:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 19:08:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "color.h"

void			ft_fill_data_aa(t_ctrl *c)
{
	char	*data;
	int		x;
	int		y;

	y = 0;
	while (y < c->scene->canv.height)
	{
		x = 0;
		while (x < c->scene->canv.width)
		{
			data = c->img.data + (y * c->img.size_line +
									x * (c->img.bit_per_pixel / 8));
			*(unsigned int *)data = ft_rgb_to_data(
									ft_color_average(c->scene->data_aa,
									SAMPLING * x, SAMPLING * y,
									SAMPLING * c->scene->canv.width));
			x++;
		}
		y++;
	}
}
