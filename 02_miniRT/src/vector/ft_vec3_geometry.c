/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_geometry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:38:57 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 01:18:54 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3		ft_vec3_reflect(t_vec3 come, t_vec3 norm)
{
	return (V_PLUS(come, V_SCALAR(norm, -2 * V_DOT(come, norm))));
}
