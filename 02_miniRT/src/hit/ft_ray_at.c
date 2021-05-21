/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:05:37 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 22:05:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_vec3		ft_ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = V_PLUS(ray->org, V_SCALAR(ray->dir, t));
	return (at);
}