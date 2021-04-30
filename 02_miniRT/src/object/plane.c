/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:33:38 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/30 00:51:46 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

t_plane			*ft_plane(t_point3 point, t_vec3 normal, t_color color)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->point = point;
	plane->normal = normal;
	plane->color = color;
	return (plane);
}