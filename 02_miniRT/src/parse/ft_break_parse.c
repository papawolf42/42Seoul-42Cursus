/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:35:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 22:15:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "alias.h"

static void			ft_destroy_scene(t_scene *s)
{
	//objects linked list free function
	//camera linked list free function
	//light linked list free function
	s->canv.width = s->canv.width;// avoid error
}

static void			ft_destroy_splits(char **splits)
{
	size_t		i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

t_bool				ft_break_parse(t_scene *s, char **splits)
{
	ft_destroy_scene(s);
	ft_destroy_splits(splits);
	return (false);
}