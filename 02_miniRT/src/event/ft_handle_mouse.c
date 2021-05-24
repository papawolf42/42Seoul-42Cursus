/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:37:45 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "event.h"
#include "exit.h"
#include "minirt.h"
#include "console.h"

int				ft_handle_mouse(int btn, int x, int y, t_ctrl *ctrl)
{
	if (y < 0)
		return (0);
	if (ft_trigger_mouse(btn, x, y, ctrl))
		if (ft_switch(ctrl))
			ft_exit_minirt(ctrl);
	ft_console_msg(ctrl, NULL);
	mlx_put_image_to_window(ctrl->mlx_ptr, ctrl->win_ptr,
													ctrl->img.img_ptr, 0, 0);
	return (0);
}
