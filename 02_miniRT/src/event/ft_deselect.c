/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:59:40 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 12:59:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int				ft_deselect(t_ctrl *c, int x, int y)
{
	if (c->mode == 'c')
		c->mode = 'C';
	else if (c->mode == 'l')
		c->mode = 'L';
	(void)x;
	(void)y;
	return (false);
}
