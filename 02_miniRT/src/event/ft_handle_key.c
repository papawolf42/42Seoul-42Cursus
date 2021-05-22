/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:20:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 19:08:06 by gunkim           ###   ########.fr       */
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
	ft_console_msg(ctrl, "key pressed");
	ft_trigger_key(ctrl, key);
	if (ft_render_multi_thread(ctrl))
		ft_exit_minirt(ctrl);
	mlx_put_image_to_window(ctrl->mlx_ptr, ctrl->win_ptr, ctrl->img.img_ptr, 0, 0);
	return (0);
}
