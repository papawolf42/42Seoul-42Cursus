/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:24:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 23:54:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "event.h"
#include "struct.h"
#include "matrix.h"
#include "object.h"

int					ft_move_forward(t_ctrl *ctrl)
{
	t_vec3			trans;
	t_camera		*cam;

	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	trans = ft_linear_transform_rotate(cam->mat_c2w, V_SET(0, 0, -UNIT_MOVE));
	if (ctrl->mode == 'C')
		cam->mat_c2w.trans = V_PLUS(cam->mat_c2w.trans, trans);
	if (ctrl->mode == 'O')
		ft_move_object(ctrl->object_selected, trans);
	return (success);
}

int					ft_move_back(t_ctrl *ctrl)
{
	t_vec3			trans;
	t_camera		*cam;

	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	trans = ft_linear_transform_rotate(cam->mat_c2w, V_SET(0, 0, UNIT_MOVE));
	if (ctrl->mode == 'C')
		cam->mat_c2w.trans = V_PLUS(cam->mat_c2w.trans, trans);
	if (ctrl->mode == 'O')
		ft_move_object(ctrl->object_selected, trans);
	return (success);
}
