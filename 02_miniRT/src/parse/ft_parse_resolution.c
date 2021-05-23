/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:47:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 17:23:46 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "alias.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

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
	s->canv.aspect_ratio = (double)s->canv.width / (double)s->canv.height;
	// if resolution parsed is bigger than max of current screen, set as max value
	// if resolution is lower than 0, throw as error
	s->data_aa = (t_color *)malloc(sizeof(t_color) * (s->canv.width * SAMPLING + 1)
											* (s->canv.height * SAMPLING + 1));
	if (s->data_aa == NUL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	s->flag_declare += 0x1;
	return (success);
}
