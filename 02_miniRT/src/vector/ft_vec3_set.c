/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:02:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 12:05:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "alias.h"
#include "utils.h"

t_vec3		ft_vset(double x, double y, double z)
{
	t_vec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3		ft_vmax(t_vec3 one, t_vec3 two)
{
	one.x = ft_max(one.x, two.x);
	one.y = ft_max(one.y, two.y);
	one.z = ft_max(one.z, two.z);
	return (one);
}

t_vec3		ft_vmin(t_vec3 one, t_vec3 two)
{
	one.x = ft_min(one.x, two.x);
	one.y = ft_min(one.y, two.y);
	one.z = ft_min(one.z, two.z);
	return (one);
}
