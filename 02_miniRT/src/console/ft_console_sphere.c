/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:44:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 14:01:14 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_sphere(t_ctrl *ctrl)
{
	t_sphere		*sphere;

	sphere = (t_sphere *)ctrl->object_selected->object;
	ft_console_type(ctrl->object_selected->type);
	ft_console_vec(TC_POINT, sphere->center);
	ft_console_real(TC_RADIUS, sphere->radius);
	ft_console_color(sphere->color);
	printf("\n\n");
}
