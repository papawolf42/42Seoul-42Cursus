/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_after.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:47:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 22:49:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"

static void		ft_light_after(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "Next light selected");
	if (ctrl->scene->idx_l == ctrl->scene->count_l - 1)
		ctrl->scene->idx_l = -1;
	ctrl->scene->idx_l++;
}

static void		ft_camera_after(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "Next camera selected");
	if (ctrl->scene->idx_c == ctrl->scene->count_c - 1)
		ctrl->scene->idx_c = -1;
	ctrl->scene->idx_c++;
}

static void		ft_object_after(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "Next object selected");
	if (ctrl->scene->idx_o == ctrl->scene->count_o - 1)
		ctrl->scene->idx_o = -1;
	ctrl->scene->idx_o++;
}

int				ft_list_after(t_ctrl *ctrl)
{
	if (ctrl->mode == 'L')
		ft_light_after(ctrl);
	else if (ctrl->mode == 'C')
		ft_camera_after(ctrl);
	else if (ctrl->mode == '\0')
		ft_object_after(ctrl);
	return (success);
}
