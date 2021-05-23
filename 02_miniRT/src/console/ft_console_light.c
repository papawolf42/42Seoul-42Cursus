/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:04:30 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 13:38:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_light(t_ctrl *ctrl)
{
	t_light		*light;

	light = (t_light *)ft_return_object(ctrl->scene->light_list,
										ctrl->scene->idx_l);
	ft_console_type(l);
	ft_console_numberof(ctrl, l);
	ft_console_vec(TC_POINT, light->p);
	ft_console_real(TC_RATIO, light->ratio);
	ft_console_color(light->color);
	printf("\n\n");
}
