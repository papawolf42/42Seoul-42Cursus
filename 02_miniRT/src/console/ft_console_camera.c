/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:06:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 13:37:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_camera(t_ctrl *ctrl)
{
	t_camera		*camera;

	camera = (t_camera *)ft_return_object(ctrl->scene->camera_list,
										ctrl->scene->idx_c);
	ft_console_type(cam);
	ft_console_numberof(ctrl, cam);
	ft_console_vec(TC_POINT, camera->origin);
	ft_console_vec(TC_NORMAL, camera->normal);
	ft_console_real(TC_FOV, camera->fov);
	printf("\n\n");
}
