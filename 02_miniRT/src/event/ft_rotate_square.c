/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:48:13 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 09:47:13 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "parse.h"

int				ft_rotate_square(t_object_list *list, t_mat44 mat)
{
	t_square		*square;

	square = (t_square *)list->object;
	square->normal = V_UNIT(ft_linear_transform_rotate(mat, square->normal));
	square->span_a = V_UNIT(ft_linear_transform_rotate(mat, square->span_a));
	square->span_b = V_UNIT(ft_linear_transform_rotate(mat, square->span_b));
	return (0);
}
