/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:20:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 16:03:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include "event.h"
#include "exit.h"
// need refactoring
#include "minirt.h"
#include "console.h"

int				ft_handle_key(int key, t_ctrl *ctrl)
{
	if (ft_trigger_key(ctrl, key))
		if (ft_switch(ctrl))
			ft_exit_minirt(ctrl);
	ft_console_msg(ctrl, NUL);
	mlx_put_image_to_window(ctrl->mlx_ptr, ctrl->win_ptr, ctrl->img.img_ptr, 0, 0);
	return (0);
}
