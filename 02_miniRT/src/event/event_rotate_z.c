/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:56:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:02:08 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "event.h"
#include "struct.h"
#include "matrix.h"
#include "object.h"

int					ft_roll_right(t_ctrl *ctrl)
{
	t_mat44			mat;
	t_camera		*cam;

	mat = ft_mat_rotate_z(-UNIT_ROTATE);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	cam->mat_c2w = ft_mat_mult(mat, cam->mat_c2w);
	return (success);
}

int					ft_roll_left(t_ctrl *ctrl)
{
	t_mat44			mat;
	t_camera		*cam;

	mat = ft_mat_rotate_z(UNIT_ROTATE);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list, ctrl->scene->idx_c);
	cam->mat_c2w = ft_mat_mult(mat, cam->mat_c2w);
	return (success);
}
