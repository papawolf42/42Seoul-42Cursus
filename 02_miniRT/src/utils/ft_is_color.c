/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:36:59 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 23:48:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

t_bool		ft_is_color(char *splits)
{
	char **s;

	s = ft_split_rt(splits, COMMA);
	if (!ft_is_integer(s[0]) || !ft_is_integer(s[1]) || !ft_is_integer(s[2]))
	{
		ft_destroy_splits(s);
		return (false);
	}
	ft_destroy_splits(s);
	return (true);
}
