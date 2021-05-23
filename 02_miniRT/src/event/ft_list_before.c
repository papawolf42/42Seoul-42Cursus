/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:38:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 12:56:34 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"
#include "console.h"

static void		ft_light_before(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, NUL);
	if (ctrl->scene->idx_l == 0)
		ctrl->scene->idx_l = ctrl->scene->count_l;
	ctrl->scene->idx_l--;
}

static void		ft_camera_before(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, NUL);
	if (ctrl->scene->idx_c == 0)
		ctrl->scene->idx_c = ctrl->scene->count_c;
	ctrl->scene->idx_c--;
}

static void		ft_object_before(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, NUL);
	if (ctrl->scene->idx_o == 0)
		ctrl->scene->idx_o = ctrl->scene->count_o;
	ctrl->scene->idx_o--;
}

int				ft_list_before(t_ctrl *ctrl)
{
	if (ctrl->mode == 'L')
		ft_light_before(ctrl);
	else if (ctrl->mode == 'C')
		ft_camera_before(ctrl);
	else if (ctrl->mode == '\0')
		ft_object_before(ctrl);
	return (true);
}
