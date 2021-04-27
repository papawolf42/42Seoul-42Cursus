/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:30:28 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/28 05:32:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"

void			ft_object_list_init(t_scene *s)
{
	s->object_list = (t_object_list *)malloc(sizeof(t_object_list));
	ft_bzero(s->object_list, sizeof(t_object_list));
}

void			ft_object_list(t_object_type type, void *object, t_scene *s)
{
	t_object_list	*node;

	node = s->object_list;
	if (node->object == NUL)
	{
		node->type = type;
		if (type == sp)
			node->object = (t_sphere *)object;
	}
	else
	{
		while (node->next)
		{
			node = node->next;
		}
			node->next = (t_object_list *)malloc(sizeof(t_object_list));
			node->next->type = type;
			if (type == sp)
				node->next->object = (t_sphere *)object;
	}
}