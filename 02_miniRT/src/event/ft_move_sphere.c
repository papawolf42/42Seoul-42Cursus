/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 01:50:49 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 02:09:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

int				ft_move_sphere(t_object_list *list, t_vec3 trans)
{
	t_sphere		*sphere;

	sphere = (t_sphere *)list->object;
	sphere->center = V_PLUS(sphere->center, trans);
	return (0);
}
