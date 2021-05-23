/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:40:40 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 13:29:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_plane(t_ctrl *ctrl)
{
	t_plane		*plane;

	plane = (t_plane *)ctrl->object_selected->object;
	ft_console_type(ctrl->object_selected->type);
	ft_console_vec(TC_POINT, plane->point);
	ft_console_vec(TC_NORMAL, plane->normal);
	ft_console_color(plane->color);
	printf("\n\n");
}
