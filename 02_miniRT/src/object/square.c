/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:19:48 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/30 19:29:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

t_square		*ft_square(t_point3 center, t_vec3 normal, double side_size, t_color color)
{
	t_square	*square;
	// double		half_s;

	square = (t_square *)malloc(sizeof(t_square));
	square->center = center;
	square->normal = V_UNIT(normal);
	square->side_size = side_size;
	// half_s = side_size / 2;
	square->color = color;
	if (V_DOT(square->normal, V_SET(0, 0, 1)) == 1)
		square->span_a = V_UNIT(V_CROSS(square->normal, V_SET(0, -1, 0)));
	else
	square->span_a = V_UNIT(V_CROSS(square->normal, V_SET(0, 1, 0)));
	if (V_DOT(square->normal, V_SET(1, 0, 0)) == 1)
		square->span_b = V_UNIT(V_CROSS(square->normal, V_SET(0, 0, -1)));
	else
	square->span_b = V_UNIT(V_CROSS(square->normal, V_SET(1, 0, 0)));
	return (square);
}