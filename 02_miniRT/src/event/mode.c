/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:31:02 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 17:35:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"

int				ft_mode_light(t_ctrl *ctrl)
{
	ft_console_msg("mode: Light mode");
	ctrl->mode = 'L';
	return (success);
}

int				ft_mode_camera(t_ctrl *ctrl)
{
	ft_console_msg("mode: Camera mode");
	ctrl->mode = 'C';
	return (success);
}

int				ft_mode_object(t_ctrl *ctrl)
{
	ft_console_msg("mode: Object mode");
	ctrl->mode = '\0';
	return (success);
}
