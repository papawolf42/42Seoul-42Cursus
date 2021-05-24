/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:27:48 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "alias.h"
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

t_bool			ft_parse_sphere(t_scene *s, char **splits)
{
	t_sphere		*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 4)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(sphere));
	if (ft_parse_vector(&sphere->center, splits[1]))
		return (ft_destroy(sphere));
	if (ft_parse_real(&sphere->radius, splits[2]))
		return (ft_destroy(sphere));
	if (ft_range_real(&sphere->radius, 0, M_INFINITY))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(sphere));
	if (ft_parse_color(&sphere->color, splits[3]))
		return (ft_destroy(sphere));
	if (ft_addback_object_list(sp, sphere, s))
		return (ft_destroy(sphere));
	return (success);
}
