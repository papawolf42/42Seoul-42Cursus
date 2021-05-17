/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:06:28 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 12:34:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "alias.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"

t_bool			ft_parse_vector(t_vec3 *dst, char *src)
{
	char		**splits;

	splits = ft_split_rt(src, COMMA);
	if (ft_strslen(splits) != 3)
		return (ft_err_msg(ERR_WRONG_ELEMENT) && ft_destroy_splits(splits));
	if (ft_parse_real(&dst->x, splits[0])
		|| ft_parse_real(&dst->y, splits[1])
		|| ft_parse_real(&dst->z, splits[2]))
		return (ft_err_msg(ERR_BAD_REAL) && ft_destroy_splits(splits));
	ft_destroy_splits(splits);
	return (success);
}
