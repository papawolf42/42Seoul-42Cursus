/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:02:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 01:26:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "alias.h"
#include "utils.h"

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
	one.x = ft_max(one.x, two.x);
	one.y = ft_max(one.y, two.y);
	one.z = ft_max(one.z, two.z);
	return (one);
}

t_vec3		ft_vec3_minimum(t_vec3 one, t_vec3 two)
{
	one.x = ft_min(one.x, two.x);
	one.y = ft_min(one.y, two.y);
	one.z = ft_min(one.z, two.z);
	return (one);
}
