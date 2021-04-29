/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:15:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/29 17:15:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"

void			ft_light_list_init(t_scene *s)
{
	s->light_list = (t_light_list *)malloc(sizeof(t_light_list));
	ft_bzero(s->light_list, sizeof(t_light_list));
}

void			ft_light_list(void *light, t_scene *s)
{
	t_light_list	*node;

	node = s->light_list;
	if (node->light == NUL)
	{
		node->light = light;
	}
	else
	{
		while (node->next)
		{
			node = node->next;
		}
			node->next = (t_light_list *)malloc(sizeof(t_light_list));
			ft_bzero(node->next, sizeof(t_light_list));
			node->next->light = light;
	}
}

t_light		*ft_light(t_point3 point, t_color color)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	light->p = point;
	light->color = color;
	return (light);
}