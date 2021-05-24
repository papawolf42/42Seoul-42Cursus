/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:20:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 12:05:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double		ft_vlen(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double		ft_vlen2(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
