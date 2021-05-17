/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:10:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/18 01:28:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "alias.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

t_bool			ft_parse_normal(t_vec3 *dst, char *src)
{
	char		**splits;

	splits = ft_split_rt(src, COMMA);
	if (ft_strslen(splits) != 3)
		return (ft_err_msg(ERR_WRONG_ELEMENT) && ft_destroy_splits(splits));
	if (ft_parse_real(&dst->x, splits[0])
		|| ft_parse_real(&dst->y, splits[1])
		|| ft_parse_real(&dst->z, splits[2]))
		return (ft_destroy_splits(splits));
	if (ft_range_real(&dst->x, -1.0, 1.0)
		|| ft_range_real(&dst->y, -1.0, 1.0)
		|| ft_range_real(&dst->z, -1.0, 1.0)
		|| (dst->x == 0 && dst->y == 0 && dst->z == 0))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy_splits(splits));
	ft_destroy_splits(splits);
	return (success);
}
