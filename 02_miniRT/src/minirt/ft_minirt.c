/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:47:40 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "struct.h"
#include "mlx.h"
#include "event.h"
#include "console.h"

t_bool		ft_minirt(t_ctrl *ctrl)
{
	ctrl->mlx_ptr = mlx_init();
	ctrl->win_ptr = mlx_new_window(ctrl->mlx_ptr,
									ctrl->scene->canv.width,
									ctrl->scene->canv.height,
									"miniRT");
	ctrl->img.img_ptr = mlx_new_image(ctrl->mlx_ptr,
										ctrl->scene->canv.width,
										ctrl->scene->canv.height);
	ctrl->img.data = mlx_get_data_addr(ctrl->img.img_ptr,
										&ctrl->img.bit_per_pixel,
										&ctrl->img.size_line,
										&ctrl->img.endian);
	if (ft_switch(ctrl))
		return (fail);
	ft_console_msg(ctrl, NULL);
	mlx_put_image_to_window(ctrl->mlx_ptr,
							ctrl->win_ptr,
							ctrl->img.img_ptr, 0, 0);
	ft_init_hook(ctrl);
	return (success);
}
