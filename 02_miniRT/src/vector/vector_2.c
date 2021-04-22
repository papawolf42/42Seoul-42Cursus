/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:21:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/22 19:04:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_vec_add(t_vec3 *one, t_vec3 *two)
{
	one->x += two->x;
	one->y += two->y;
	one->z += two->z;
}

void		ft_vec_add2(t_vec3 *one, t_vec3 *two)
{
	one->x += two->x;
	one->y += two->y;
	one->z += two->z;
}

void		ft_vec_sub(t_vec3 *one, t_vec3 *two)
{
	one->x -= two->x;
	one->y -= two->y;
	one->z -= two->z;
}

void		ft_vec_sub2(t_vec3 *one, t_vec3 *two)
{
	one->x -= two->x;
	one->y -= two->y;
	one->z -= two->z;
}