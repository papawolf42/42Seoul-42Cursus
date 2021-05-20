/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:24:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 10:38:12 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "event.h"
#include "struct.h"
#include "matrix.h"
#include "object.h"

int					ft_move_left(t_ctrl *ctrl)
{
	t_vec3			trans;
	t_camera		*cam;

	trans = V_SET(-UNIT_MOVE, 0, 0);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	cam->mat_c2w.trans = V_PLUS(cam->mat_c2w.trans, ft_linear_transform_rotate(cam->mat_c2w, trans));
	return (success);
}

int					ft_move_right(t_ctrl *ctrl)
{
	t_vec3			trans;
	t_camera		*cam;

	trans = V_SET(UNIT_MOVE, 0, 0);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	cam->mat_c2w.trans = V_PLUS(cam->mat_c2w.trans, ft_linear_transform_rotate(cam->mat_c2w, trans));
	return (success);
}
