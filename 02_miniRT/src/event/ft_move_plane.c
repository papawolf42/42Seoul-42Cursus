/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:02:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:47:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"

int				ft_move_plane(t_object_list *list, t_vec3 trans)
{
	t_plane		*plane;

	plane = (t_plane *)list->object;
	plane->point = ft_vplus(plane->point, trans);
	return (0);
}
