/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:07:49 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

static void		ft_free_object_list(t_object_list **lst)
{
	t_object_list	*next;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void			ft_free_scene(t_scene *scene)
{
	free(scene->data_aa);
	ft_free_object_list(&scene->camera_list);
	ft_free_object_list(&scene->light_list);
	ft_free_object_list(&scene->object_list);
	free(scene);
}
