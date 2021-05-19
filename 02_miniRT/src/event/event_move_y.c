/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:24:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 22:06:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "event.h"
#include "struct.h"
#include "matrix.h"
#include "object.h"

int					ft_move_down(t_ctrl *ctrl)
{
	t_mat44			mat;
	t_camera		*cam;

	mat = ft_matrix_identity();
	mat.trans = V_SET(0, -1 * UNIT_MOVE, 0);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	cam->origin = ft_linear_transform(mat, cam->origin);
	return (success);
}

int					ft_move_up(t_ctrl *ctrl)
{
	t_mat44			mat;
	t_camera		*cam;

	mat = ft_matrix_identity();
	mat.trans = V_SET(0, UNIT_MOVE, 0);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	cam->origin = ft_linear_transform(mat, cam->origin);
	return (success);
}
