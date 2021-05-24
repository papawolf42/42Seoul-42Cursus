/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:56:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 11:27:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "event.h"
#include "struct.h"
#include "matrix.h"
#include "object.h"

int					ft_pitch_up(t_ctrl *ctrl)
{
	t_mat44			mat;
	t_camera		*cam;

	mat = ft_mat_rotate_x(-ctrl->unit_rotate);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list,
												ctrl->scene->idx_c);
	if (ctrl->mode == 'C')
		cam->mat_c2w = ft_mat_mult_rotate(mat, cam->mat_c2w);
	if (ctrl->mode == 'c' || ctrl->mode == 'l')
		ft_rotate_object(ctrl->object_selected, mat);
	return (true);
}

int					ft_pitch_down(t_ctrl *ctrl)
{
	t_mat44			mat;
	t_camera		*cam;

	mat = ft_mat_rotate_x(ctrl->unit_rotate);
	cam = (t_camera *)ft_return_object(ctrl->scene->camera_list,
												ctrl->scene->idx_c);
	if (ctrl->mode == 'C')
		cam->mat_c2w = ft_mat_mult_rotate(mat, cam->mat_c2w);
	if (ctrl->mode == 'c' || ctrl->mode == 'l')
		ft_rotate_object(ctrl->object_selected, mat);
	return (true);
}
