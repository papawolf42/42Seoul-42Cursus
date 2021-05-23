/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_multiplication.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:32:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 01:21:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "error.h"

t_vec3		ft_vec3_scalar(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec3		ft_vec3_mult(t_vec3 one, t_vec3 two)
{
	one.x *= two.x;
	one.y *= two.y;
	one.z *= two.z;
	return (one);
}

double		ft_vec3_dot(t_vec3 one, t_vec3 two)
{
	return (one.x * two.x + one.y * two.y + one.z * two.z);
}

t_vec3		ft_vec3_cross(t_vec3 one, t_vec3 two)
{
	t_vec3	new;

	new.x = one.y * two.z - one.z * two.y;
	new.y = one.z * two.x - one.x * two.z;
	new.z = one.x * two.y - one.y * two.x;
	return (new);
}

t_vec3		ft_vec3_unit(t_vec3 vec)
{
	double		veclen;

	veclen = ft_vec3_len(vec);
	if (veclen == 0)
		ft_err_msg("cannot be devieded 0");
	return (ft_vec3_scalar(vec, 1.0 / veclen));
}
