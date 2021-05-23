/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:44:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 13:29:14 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_square(t_ctrl *ctrl)
{
	t_square		*square;

	square = (t_square *)ctrl->object_selected->object;
	ft_console_type(ctrl->object_selected->type);
	ft_console_vec(TC_POINT, square->center);
	ft_console_vec(TC_NORMAL, square->normal);
	ft_console_real(TC_SIDE_LEN, square->side_len);
	ft_console_color(square->color);
	printf("\n");
}
