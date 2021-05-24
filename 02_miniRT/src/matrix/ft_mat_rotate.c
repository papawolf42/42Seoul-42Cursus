/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:52:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:44:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"

t_mat44				ft_mat_rotate_x(double a)
{
	return (ft_mat_set(ft_vset(1, 0, 0),
						ft_vset(0, cos(a), -sin(a)),
						ft_vset(0, sin(a), cos(a)),
						ft_vset(0, 0, 0)));
}

t_mat44				ft_mat_rotate_y(double a)
{
	return (ft_mat_set(ft_vset(cos(a), 0, sin(a)),
						ft_vset(0, 1, 0),
						ft_vset(-sin(a), 0, cos(a)),
						ft_vset(0, 0, 0)));
}

t_mat44				ft_mat_rotate_z(double a)
{
	return (ft_mat_set(ft_vset(cos(a), -sin(a), 0),
						ft_vset(sin(a), cos(a), 0),
						ft_vset(0, 0, 1),
						ft_vset(0, 0, 0)));
}
