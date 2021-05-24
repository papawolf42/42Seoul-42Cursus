/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:24:06 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 01:37:37 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "color.h"

static t_color		ft_sepia_filter(t_color color)
{
	t_color result;

	result.x = color.x * 0.393 + color.y * 0.769 + color.z * 0.189;
	result.y = color.x * 0.349 + color.y * 0.686 + color.z * 0.168;
	result.z = color.x * 0.272 + color.y * 0.534 + color.z * 0.131;
	result = ft_vmin(result, ft_vset(1.0, 1.0, 1.0));
	return (result);
}

t_color				ft_filter(t_scene *s, t_color color)
{
	if (s->filter == 'r')
	{
		color.y = 0;
		color.z = 0;
	}
	else if (s->filter == 'g')
	{
		color.x = 0;
		color.z = 0;
	}
	else if (s->filter == 'b')
	{
		color.x = 0;
		color.y = 0;
	}
	else if (s->filter == 's')
		color = ft_sepia_filter(color);
	return (color);
}
