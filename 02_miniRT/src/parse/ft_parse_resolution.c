/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:47:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 00:24:42 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "alias.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

static t_bool	ft_resolution_must_bigger_zero(t_scene *s)
{
	if (s->canv.width <= 0 || s->canv.height <= 0)
		return (fail);
	return (success);
}

static void		ft_resolution_must_lower_max(t_scene *s)
{
	if (s->canv.width > s->canv.max_w)
		s->canv.width = s->canv.max_w;
	if (s->canv.height > s->canv.max_h)
		s->canv.height = s->canv.max_h;
}

t_bool			ft_parse_resolution(t_scene *s, char **splits)
{
	if (s->flag_declare & 0x1)
		return (ft_err_msg(ERR_ENOUGH_DECLARE));
	if (ft_strslen(splits) != 3)
		return (ft_err_msg(ERR_WORNG_ARG));
	if (ft_parse_integer(&s->canv.width, splits[1]))
		return (ft_err_msg(ERR_BAD_INT));
	if (ft_parse_integer(&s->canv.height, splits[2]))
		return (ft_err_msg(ERR_BAD_INT));
	if (ft_resolution_must_bigger_zero(s))
		return (ft_err_msg(ERR_RES_LOW_ZERO));
	ft_resolution_must_lower_max(s);
	s->canv.aspect_ratio = (double)s->canv.width / (double)s->canv.height;
	s->data_aa = (t_color *)malloc(sizeof(t_color)
										* (s->canv.width * SAMPLING + 1)
										* (s->canv.height * SAMPLING + 1));
	if (s->data_aa == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	s->flag_declare += 0x1;
	return (success);
}
