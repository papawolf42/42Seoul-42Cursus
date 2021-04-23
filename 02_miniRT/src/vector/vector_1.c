/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:02:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/22 20:25:46 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

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
** vec3 길이의 제곱 (물리적 의미는 없지만, 계산상 제곱을 구할 필요가 있을 때)
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

