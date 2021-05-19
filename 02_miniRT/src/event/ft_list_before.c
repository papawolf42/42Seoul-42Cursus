/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:38:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 17:38:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"

static void		ft_light_before(t_scene *scene)
{
	if (scene->idx_l == 0)
		scene->idx_l = scene->count_l;
	scene->idx_l--;
}

static void		ft_camera_before(t_scene *scene)
{
	ft_console_msg("Before camera selected");
	if (scene->idx_c == 0)
		scene->idx_c = scene->count_c;
	scene->idx_c--;
}

static void		ft_object_before(t_scene *scene)
{
	if (scene->idx_o == 0)
		scene->idx_o = scene->count_o;
	scene->idx_o--;
}

int				ft_list_before(t_ctrl *ctrl)
{
	if (ctrl->mode == 'L')
		ft_light_before(ctrl->scene);
	else if (ctrl->mode == 'C')
		ft_camera_before(ctrl->scene);
	else if (ctrl->mode == '\0')
		ft_object_before(ctrl->scene);
	return (success);
}
