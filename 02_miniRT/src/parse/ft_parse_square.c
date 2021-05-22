/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:19:48 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 09:54:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

static void		ft_square_set_initial(t_square *square)
{
	if (V_DOT(square->normal, square->axis_up) == 1)
		square->span_a = V_UNIT(V_CROSS(square->normal, square->axis_up));
	else
		square->span_a = V_UNIT(V_CROSS(square->normal, square->axis_up));
	square->span_b = V_UNIT(V_CROSS(square->normal, square->span_a));
}

t_bool			ft_parse_square(t_scene *s, char **splits)
{
	t_square	*square;

	square = (t_square *)malloc(sizeof(t_square));
	if (square == NUL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 5)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(square));
	if (ft_parse_vector(&square->center, splits[1]))
		return (ft_destroy(square));
	if (ft_parse_normal(&square->normal, splits[2]))
		return (ft_destroy(square));
	if (ft_parse_real(&square->side_len, splits[3]))
		return (ft_destroy(square));
	if (ft_range_real(&square->side_len, 0, M_INFINITY))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(square));
	if (ft_parse_color(&square->color, splits[4]))
		return (ft_destroy(square));
	square->axis_up = V_SET(0, 1, 0);
	ft_square_set_initial(square);
	if (ft_addback_object_list(sq, square, s))
		return (ft_destroy(square));
	return (success);
}
