/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:47:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 22:21:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "alias.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

t_bool			ft_parse_resolution(t_scene *s, char **splits)
{
	if (ft_strslen(splits) != 3)
		return (!ft_err_msg(ERR_PAR_NOT_MATCH_ARG_NUM) && ft_break_parse(s, splits));
	if (!ft_is_integer(splits[1]) || !ft_is_integer(splits[2]))
		return (!ft_err_msg(ERR_NOT_INT) && ft_break_parse(s, splits));
		s->canv.width = ft_atoi(splits[1]);
		s->canv.height = ft_atoi(splits[2]);
		s->canv.aspect_ratio = (double)s->canv.width / (double)s->canv.height;
	// if resolution parsed is bigger than max of current screen, set as max value
	// if resolution is lower than 0, throw as error
	return (true);
}