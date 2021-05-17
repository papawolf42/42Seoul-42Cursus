/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:18:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 23:28:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"

t_bool			ft_parse_ambient(t_scene *s, char **splits)
{
	if (ft_strslen(splits) != 3)
		return (ft_err_msg(ERR_WORNG_ARG));
	if (ft_parse_real(&s->ambient.ratio, splits[1]))
		return (ft_err_msg(ERR_BAD_REAL));
	if (ft_range_real(&s->ambient.ratio, 0, 1.0))
		return (ft_err_msg(ERR_BAD_RANGE));
	if (ft_parse_color(&s->ambient.color, splits[2]))
		return (ft_err_msg(ERR_BAD_COLOR));
	return (success);
}
