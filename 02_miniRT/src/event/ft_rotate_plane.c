/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:28:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 02:47:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int				ft_rotate_plane(t_object_list *list, t_mat44 mat)
{
	t_plane		*plane;

	plane = (t_plane *)list->object;
	plane->normal = ft_linear_transform_rotate(mat, plane->normal);
	return (0);
}
