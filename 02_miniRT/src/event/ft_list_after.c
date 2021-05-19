/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_after.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:47:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 17:39:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"

static void		ft_light_after(t_scene *scene)
{
	if (scene->idx_l == scene->count_l - 1)
		scene->idx_l = -1;
	scene->idx_l++;
}

static void		ft_camera_after(t_scene *scene)
{
	ft_console_msg("Next camera selected");
	if (scene->idx_c == scene->count_c - 1)
		scene->idx_c = -1;
	scene->idx_c++;
}

static void		ft_object_after(t_scene *scene)
{
	if (scene->idx_o == scene->count_o - 1)
		scene->idx_o = -1;
	scene->idx_o++;
}

int				ft_list_after(t_ctrl *ctrl)
{
	if (ctrl->mode == 'L')
		ft_light_after(ctrl->scene);
	else if (ctrl->mode == 'C')
		ft_camera_after(ctrl->scene);
	else if (ctrl->mode == '\0')
		ft_object_after(ctrl->scene);
	return (success);
}
