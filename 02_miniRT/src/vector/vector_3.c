/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:32:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/22 20:25:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		ft_vec_scalar(t_vec3 *vec, double t)
{
	vec->x *= t;
	vec->y *= t;
	vec->z *= t;
}

double		ft_vec_dot(t_vec3 *one, t_vec3 *two)
{
	return (one->x * two->x + one->y * two->y + one->z * two->z);
}

void		ft_vec_vcross(t_vec3 *new, t_vec3 *one, t_vec3 *two)
{
	new->x = one->y * two->z - one->z * two->y;
	new->y = one->z * two->x - one->x * two->z;
	new->z = one->x * two->y - one->y * two->x;
}

void		ft_vec_unit(t_vec3 *vec)
{
	double veclen;

	veclen = ft_vec_len(vec);
	if (veclen == 0)
	{
		//ft_error_handler(ERROR_DIVIDE_ZERO);
	}
	ft_vec_scalar(vec, 1 / veclen);
}