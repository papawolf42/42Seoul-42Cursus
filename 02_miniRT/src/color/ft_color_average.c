/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_average.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:05:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:48:17 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"

t_color			ft_color_average(t_color *data, int x, int y, int width)
{
	t_color		c;
	int			dx;
	int			dy;

	c = ft_vset(0, 0, 0);
	dy = 0;
	while (dy < SAMPLING)
	{
		dx = 0;
		while (dx < SAMPLING)
		{
			c = ft_vplus(c, data[((y + dy) * width) + (x + dx)]);
			dx++;
		}
		dy++;
	}
	c = ft_vscalar(c, 1.0 / (SAMPLING * SAMPLING));
	return (c);
}
