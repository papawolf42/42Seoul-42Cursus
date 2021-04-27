/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/28 05:34:36 by gunkim           ###   ########.fr       */
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
	ctrl->scene->canv.width = 1024;
	ctrl->scene->canv.height = 768;
	ctrl->scene->canv.aspect_ratio = (double)1024 / (double)768;
	ft_camera_list_init(ctrl->scene);
	ft_camera_list(ft_camera(V_SET(0, 0, 0), 2.0, 1.0, ctrl->scene->canv.aspect_ratio), ctrl->scene);
	ft_object_list_init(ctrl->scene);
	ft_object_list(sp, ft_sphere(V_SET(0, 0, -1), 0.5), ctrl->scene);
	ft_object_list(sp, ft_sphere(V_SET(0, -100.5, -1), 100), ctrl->scene);
	/* to avoid warning */
	rt_file = NUL;
	/* to avoid warning */
}