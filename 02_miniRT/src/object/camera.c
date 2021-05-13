/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:23:38 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/13 20:26:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "struct.h"

t_camera		*ft_camera(t_point3 origin, t_vec3 normal, double fov, double v_height, double focal_length, double ratio)
{
	t_camera	*c;

	c = (t_camera *)malloc(sizeof(t_camera));
	c->origin = origin;
	c->normal = V_UNIT(normal);
	c->fov = 2 * tan((fov / 2) * (M_PI / 180));
	c->view_h = v_height;
	c->view_w = v_height * ratio;
	c->vertical = V_SET(0, c->view_h, 0);
	c->horizontal = V_SET(c->view_w, 0, 0);
	c->left_top = V_MINUS(V_PLUS(V_MINUS(origin, V_SCALAR(c->horizontal, 0.5)), V_SCALAR(c->vertical, 0.5)), V_SET(0, 0, focal_length));
	return (c);
}