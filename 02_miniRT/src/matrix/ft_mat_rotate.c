/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:52:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:12:13 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"

t_mat44				ft_mat_rotate_x(double a)
{
	return (ft_mat_set(V_SET(1, 0, 0),
						V_SET(0, cos(a), -sin(a)),
						V_SET(0, sin(a), cos(a)),
						V_SET(0, 0, 0)));
}

t_mat44				ft_mat_rotate_y(double a)
{
	return (ft_mat_set(V_SET(cos(a), 0, sin(a)),
						V_SET(0, 1, 0),
						V_SET(-sin(a), 0, cos(a)),
						V_SET(0, 0, 0)));
}

t_mat44				ft_mat_rotate_z(double a)
{
	return (ft_mat_set(V_SET(cos(a), -sin(a), 0),
						V_SET(sin(a), cos(a), 0),
						V_SET(0, 0, 1),
						V_SET(0, 0, 0)));
}
