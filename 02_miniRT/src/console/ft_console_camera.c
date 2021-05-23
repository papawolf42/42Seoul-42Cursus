/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:06:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 15:36:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
	ft_console_real(TC_FOV, 2 * atan(camera->fov / 2) * (180 / M_PI));
	printf("\n\n");
}
