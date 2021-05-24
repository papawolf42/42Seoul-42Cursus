/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:18:13 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 01:38:04 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int				ft_rotate_filter(t_ctrl *c)
{
	if (c->scene->filter == '\0')
		c->scene->filter = 's';
	else if (c->scene->filter == 's')
		c->scene->filter = 'r';
	else if (c->scene->filter == 'r')
		c->scene->filter = 'g';
	else if (c->scene->filter == 'g')
		c->scene->filter = 'b';
	else if (c->scene->filter == 'b')
		c->scene->filter = '\0';
	return (true);
}
