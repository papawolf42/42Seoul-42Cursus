/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:02:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/29 17:37:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "alias.h"

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

t_vec3		ft_vec3_maximum(t_vec3 one, t_vec3 two)
{
	MAX(one.x, two.x);
	MAX(one.y, two.y);
	MAX(one.z, two.z);
	return (one);
}

t_vec3		ft_vec3_minimum(t_vec3 one, t_vec3 two)
{
	MIN(one.x, two.x);
	MIN(one.y, two.y);
	MIN(one.z, two.z);
	return (one);
}
