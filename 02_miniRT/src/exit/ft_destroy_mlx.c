/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:04:17 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:10:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"

void		ft_destroy_mlx(t_ctrl *ctrl)
{
	if (ctrl->img.img_ptr)
		mlx_destroy_image(ctrl->mlx_ptr, ctrl->img.img_ptr);
	if (ctrl->win_ptr)
		mlx_destroy_window(ctrl->mlx_ptr, ctrl->win_ptr);
}
