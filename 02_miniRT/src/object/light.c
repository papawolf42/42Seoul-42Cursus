/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:15:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/01 13:42:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"

t_light		*ft_light(t_point3 point, t_color color)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	light->p = point;
	light->color = color;
	return (light);
}