/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:30:28 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/18 01:02:08 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"

void			ft_init_object_list(t_scene *s)
{
	ft_bzero(s, sizeof(t_scene));
	s->object_list = (t_object_list *)malloc(sizeof(t_object_list));
	ft_bzero(s->object_list, sizeof(t_object_list));
	s->camera_list = (t_object_list *)malloc(sizeof(t_object_list));
	ft_bzero(s->camera_list, sizeof(t_object_list));
	s->light_list = (t_object_list *)malloc(sizeof(t_object_list));
	ft_bzero(s->light_list, sizeof(t_object_list));
}

void			ft_addback_object_list(t_object_type type, void *object, t_object_list *list)
{
	t_object_list	*node;

	node = list;
	if (node->object == NUL)
	{
		node->type = type;
		node->object = object;
	}
	else
	{
		while (node->next)
		{
			node = node->next;
		}
			node->next = (t_object_list *)malloc(sizeof(t_object_list));
			ft_bzero(node->next, sizeof(t_object_list));
			node->next->type = type;
			node->next->object = object;
	}
}