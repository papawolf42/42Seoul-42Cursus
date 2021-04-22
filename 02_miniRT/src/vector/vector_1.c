/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:02:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** vec3 생성자
*/
void		ft_vec_set(t_vec3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

/*
** vec3 길이제곱
*/
double		ft_vec_len2(t_vec3 *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

/*
** vec3 길이
*/
double		ft_vec_len(t_vec3 *vec)
{
	return (sqrt(ft_vec_len2(vec)));
}

