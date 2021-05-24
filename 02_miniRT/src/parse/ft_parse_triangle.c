/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:53:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

void					ft_triangle_set(t_triangle *triangle)
{
	triangle->ab = ft_vminus(triangle->b, triangle->a);
	triangle->bc = ft_vminus(triangle->c, triangle->b);
	triangle->ca = ft_vminus(triangle->a, triangle->c);
	triangle->normal = ft_vunit(ft_vcross(triangle->ab, triangle->bc));
}

t_bool					ft_parse_triangle(t_scene *s, char **splits)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	if (triangle == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 5)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(triangle));
	if (ft_parse_vector(&triangle->a, splits[1]))
		return (ft_destroy(triangle));
	if (ft_parse_vector(&triangle->b, splits[2]))
		return (ft_destroy(triangle));
	if (ft_parse_vector(&triangle->c, splits[3]))
		return (ft_destroy(triangle));
	if (ft_parse_color(&triangle->color, splits[4]))
		return (ft_destroy(triangle));
	ft_triangle_set(triangle);
	if (ft_addback_object_list(tr, triangle, s))
		return (ft_destroy(triangle));
	return (success);
}
