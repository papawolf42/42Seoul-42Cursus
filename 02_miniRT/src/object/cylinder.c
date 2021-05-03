/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:53:04 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/02 14:11:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"

t_cylinder		*ft_cylinder(t_point3 center_bottom, t_vec3 axis, double diameter, double height, t_color color)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	cylinder->center_bottom = center_bottom;
	cylinder->center_top = V_PLUS(center_bottom, V_SCALAR(axis, height));
	cylinder->axis = V_UNIT(axis);
	cylinder->radius = diameter / 2;
	cylinder->height = height;
	cylinder->color = color;
	return (cylinder);
}