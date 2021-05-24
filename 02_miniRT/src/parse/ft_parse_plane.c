/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:49:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

t_bool			ft_parse_plane(t_scene *s, char **splits)
{
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 4)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(plane));
	if (ft_parse_vector(&plane->point, splits[1]))
		return (ft_destroy(plane));
	if (ft_parse_normal(&plane->normal, splits[2]))
		return (ft_destroy(plane));
	if (ft_parse_color(&plane->color, splits[3]))
		return (ft_destroy(plane));
	if (ft_addback_object_list(pl, plane, s))
		return (ft_destroy(plane));
	return (success);
}
