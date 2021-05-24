/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_plus_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:21:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 12:05:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3		ft_vplus(t_vec3 one, t_vec3 two)
{
	one.x += two.x;
	one.y += two.y;
	one.z += two.z;
	return (one);
}

t_vec3		ft_vminus(t_vec3 one, t_vec3 two)
{
	one.x -= two.x;
	one.y -= two.y;
	one.z -= two.z;
	return (one);
}
