/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/05 12:21:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"
#include "vector.h"
#include "alias.h"

void		ft_parse_rt(t_ctrl *ctrl, char *rt_file)
{
	ctrl->scene = (t_scene *)malloc(sizeof(t_scene));
	ctrl->scene->canv.width = 1600;
	ctrl->scene->canv.height = 900;
	ctrl->scene->canv.aspect_ratio = (double)ctrl->scene->canv.width / (double)ctrl->scene->canv.height;
	ft_object_list_init(ctrl->scene);
	ft_object_list(cam, ft_camera(V_SET(0, 0, 0), 2.0, 1.0, ctrl->scene->canv.aspect_ratio), ctrl->scene->camera_list);

	ft_object_list(l, ft_light(V_POINT(0, 1, -2.8), V_COLOR(0.6, 1, 1)), ctrl->scene->light_list);
	ft_object_list(l, ft_light(V_POINT(1, 1.5, 0), V_COLOR(12, 12, 12)), ctrl->scene->light_list);
	ft_object_list(sq, ft_square(V_POINT(0, 0, -5), V_SET(0, 0, 1), 5, V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	ft_object_list(sq, ft_square(V_POINT(2.5, 0, -2.5), V_SET(1, 0, 0), 5, V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	ft_object_list(sq, ft_square(V_POINT(-2.5, 0, -2.5), V_SET(1, 0, 0), 5, V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	ft_object_list(pl, ft_plane(V_POINT(0, 2.5, 0), V_SET(0, -1, 0), V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	ft_object_list(pl, ft_plane(V_POINT(0, -2, 0), V_SET(0, 1, 0), V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	ft_object_list(cy, ft_cylinder(V_POINT(0.5,-2,-2.2),V_SET(0,1,0), 1, 1.5, V_COLOR(0.2,0.18,0.3)), ctrl->scene->object_list);

	/* to avoid warning */
	rt_file = NUL;
	/* to avoid warning */
}