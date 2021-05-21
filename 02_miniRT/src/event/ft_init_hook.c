/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:07:52 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 23:35:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "exit.h"
#include "event.h"
#include "struct.h"

void			ft_init_hook(t_ctrl *ctrl)
{
	mlx_hook(ctrl->win_ptr, EVENT_EXIT_WINDOW, MASK_EXITWINDOW, ft_exit_minirt, ctrl);
	mlx_hook(ctrl->win_ptr, EVENT_KEYPRESS, MASK_KEYPRESS, ft_handle_key, ctrl);
	mlx_hook(ctrl->win_ptr, EVENT_BUTTONPRESS, 1L << 0, ft_trigger_mouse, ctrl);
	mlx_loop(ctrl->mlx_ptr);
}
