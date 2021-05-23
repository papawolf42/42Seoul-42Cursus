/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_mode_and_object.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:22:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:03:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void			ft_console_object(t_ctrl *ctrl, t_object_type type)
{
	int						idx;
	static t_pft_console	pft_console[] = {
		{sp, ft_console_sphere},
		{pl, ft_console_plane},
		{sq, ft_console_square},
		{cy, ft_console_cylinder},
		{tr, ft_console_triangle},
		{no, NUL}
	};

	idx = 0;
	while (pft_console[idx].type != no && pft_console[idx].type != type)
		idx++;
	if (pft_console[idx].type == no)
		return ;
	pft_console[idx].console(ctrl);
}

void			ft_console_mode_and_object(t_ctrl *ctrl)
{
	if (ctrl->mode == 'L')
	{
		printf("%s%13s%s %13s %13s\n\n", TC_INVERT, TC_MODE_LIGHT, TC_RESET,
									TC_MODE_CAMERA, TC_MODE_OBJECT);
		ft_console_light(ctrl);
	}
	else if (ctrl->mode == 'C')
	{
		printf("%13s %s%13s%s %13s\n\n", TC_MODE_LIGHT, TC_INVERT,
							TC_MODE_CAMERA, TC_RESET, TC_MODE_OBJECT);
		ft_console_camera(ctrl);
	}
	else if (ctrl->mode == 'c' || ctrl->mode == 'l')
	{
		printf("%13s %13s %s%13s%s\n\n", TC_MODE_LIGHT, TC_MODE_CAMERA,
									TC_INVERT, TC_MODE_OBJECT, TC_RESET);
		ft_console_object(ctrl, ctrl->object_selected->type);
	}
}
