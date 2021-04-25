/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:02:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/25 20:39:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** vec3 constructor
*/
t_vec3		ft_vec3_set(double x, double y, double z)
{
	t_vec3		vec;
	
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
