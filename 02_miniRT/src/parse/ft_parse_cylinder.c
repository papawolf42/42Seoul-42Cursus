/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:53:04 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 23:27:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

void					ft_cylinder_set(t_cylinder *cyl)
{
	cyl->center_top = V_PLUS(cyl->center_top, V_SCALAR(cyl->axis, cyl->height));
	cyl->axis = V_UNIT(cyl->axis);
	cyl->radius = cyl->radius / 2;
}

t_bool					ft_parse_cylinder(t_scene *s, char **splits)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NUL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 6)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(cylinder));
	if (ft_parse_vector(&cylinder->center_bottom, splits[1]))
		return (ft_destroy(cylinder));
	if (ft_parse_normal(&cylinder->axis, splits[2]))
		return (ft_destroy(cylinder));
	if (ft_parse_real(&cylinder->radius, splits[3]))
		return (ft_destroy(cylinder));
	if (ft_range_real(&cylinder->radius, 0, M_INFINITY))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(cylinder));
	if (ft_parse_real(&cylinder->height, splits[4]))
		return (ft_destroy(cylinder));
	if (ft_range_real(&cylinder->height, 0, M_INFINITY))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(cylinder));
	if (ft_parse_color(&cylinder->color, splits[5]))
		return (ft_destroy(cylinder));
	ft_cylinder_set(cylinder);
	if (ft_addback_object_list(cy, cylinder, s))
		return (ft_destroy(cylinder));
	return (success);
}
