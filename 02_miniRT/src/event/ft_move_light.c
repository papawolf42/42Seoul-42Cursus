/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 01:36:29 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:47:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "parse.h"
#include "object.h"

int				ft_move_light(t_scene *scene, t_vec3 trans)
{
	t_light		*light;

	light = (t_light *)ft_return_object(scene->light_list, scene->idx_l);
	light->p = ft_vplus(light->p, trans);
	return (0);
}
