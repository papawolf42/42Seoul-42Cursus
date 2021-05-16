/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 21:57:12 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "alias.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

t_bool			ft_parse_color(t_color *dst, char *src)
{
	char		**splits;

	splits = ft_split_rt(src, COMMA);
	if (ft_strslen(splits) != 3)
		return (ft_destroy_splits(splits));
	if (ft_parse_color_integer(&dst->x, splits[0])
		|| ft_parse_color_integer(&dst->y, splits[1])
		|| ft_parse_color_integer(&dst->z, splits[2]))
		return (ft_err_msg(ERR_BAD_INT) && ft_destroy_splits(splits));
	if (ft_range_real(&dst->x, 0, 1.0)
		|| ft_range_real(&dst->y, 0, 1.0)
		|| ft_range_real(&dst->z, 0, 1.0))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy_splits(splits));
	ft_destroy_splits(splits);
	return (success);
}
