/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:59:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 13:29:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_triangle(t_ctrl *ctrl)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)ctrl->object_selected->object;
	ft_console_type(ctrl->object_selected->type);
	ft_console_vec(TC_POINT, triangle->a);
	ft_console_vec(TC_POINT, triangle->b);
	ft_console_vec(TC_POINT, triangle->c);
	ft_console_color(triangle->color);
	printf("\n");
}
