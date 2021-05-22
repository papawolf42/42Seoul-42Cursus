/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:31:02 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 16:10:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"
#include "console.h"

int				ft_mode_light(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "mode: Light mode");
	ctrl->mode = 'L';
	return (success);
}

int				ft_mode_camera(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "mode: Camera mode");
	ctrl->mode = 'C';
	return (success);
}

int				ft_mode_object(t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "mode: Object mode");
	ctrl->mode = 'O';
	return (success);
}
