/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:20:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 22:44:10 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include "event.h"
#include "exit.h"
// need refactoring
#include "minirt.h"

int				ft_handle_key(int key, t_ctrl *ctrl)
{
	ft_console_msg(ctrl, "key pressed");
	ft_trigger_event(ctrl, key);
	if (ft_render(ctrl))
		ft_exit_minirt(ctrl);
	mlx_put_image_to_window(ctrl->mlx_ptr, ctrl->win_ptr, ctrl->img.img_ptr, 0, 0);
	return (0);
}
