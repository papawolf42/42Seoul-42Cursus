/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:57:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 11:58:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_cylinder(t_ctrl *ctrl)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)ctrl->object_selected->object;
	ft_console_type(ctrl->object_selected->type);
	ft_console_vec(TC_POINT, cylinder->center_bottom);
	ft_console_vec(TC_AXIS, cylinder->axis);
	ft_console_real(TC_RADIUS, cylinder->radius);
	ft_console_real(TC_SIDE_LEN, cylinder->height);
	ft_console_color(cylinder->color);
}
