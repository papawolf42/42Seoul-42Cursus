/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:30:28 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 00:28:53 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"
#include "error.h"

t_bool					ft_init_object_list(t_scene *s)
{
	s->object_list = (t_object_list *)malloc(sizeof(t_object_list));
	if (s->object_list == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	ft_bzero(s->object_list, sizeof(t_object_list));
	s->camera_list = (t_object_list *)malloc(sizeof(t_object_list));
	if (s->camera_list == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	ft_bzero(s->camera_list, sizeof(t_object_list));
	s->light_list = (t_object_list *)malloc(sizeof(t_object_list));
	if (s->light_list == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	ft_bzero(s->light_list, sizeof(t_object_list));
	return (success);
}

static t_object_list	*ft_return_object_list(t_object_type type, t_scene *s)
{
	if (type == cam)
	{
		s->count_c++;
		return (s->camera_list);
	}
	else if (type == l)
	{
		s->count_l++;
		return (s->light_list);
	}
	s->count_o++;
	return (s->object_list);
}

t_bool					ft_addback_object_list(t_object_type type,
													void *object, t_scene *s)
{
	t_object_list	*node;

	node = ft_return_object_list(type, s);
	if (node->object == NULL)
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
		if (node->next == NULL)
			return (ft_err_msg(ERR_MALLOC_FAIL));
		ft_bzero(node->next, sizeof(t_object_list));
		node->next->type = type;
		node->next->object = object;
	}
	return (success);
}
