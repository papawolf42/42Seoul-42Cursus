/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_geometry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:38:57 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:49:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3		ft_vreflect(t_vec3 come, t_vec3 norm)
{
	return (ft_vplus(come, ft_vscalar(norm, -2 * ft_vdot(come, norm))));
}
