/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_plus_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:21:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/25 20:25:53 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Add vectors.c
*/
t_vec3		ft_vec3_plus(t_vec3 one, t_vec3 two)
{
	one.x += two.x;
	one.y += two.y;
	one.z += two.z;
	return (one);
}

/*
** Subtract vectors
*/
t_vec3		ft_vec3_minus(t_vec3 one, t_vec3 two)
{
	one.x -= two.x;
	one.y -= two.y;
	one.z -= two.z;
	return (one);
}
