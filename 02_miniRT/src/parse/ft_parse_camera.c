/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:23:38 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:57:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "error.h"
#include "parse.h"
#include "utils.h"
#include "object.h"

t_bool			ft_parse_camera(t_scene *s, char **splits)
{
	t_camera	*c;

	c = (t_camera *)malloc(sizeof(t_camera));
	if (c == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 4)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(c));
	if (ft_parse_vector(&c->origin, splits[1]))
		return (ft_destroy(c));
	if (ft_parse_normal(&c->normal, splits[2]))
		return (ft_destroy(c));
	if (ft_parse_real(&c->fov, splits[3]))
		return (ft_destroy(c));
	if (!(0 < c->fov && c->fov < 180))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(c));
	c->normal = ft_vunit(c->normal);
	c->fov = 2 * tan((c->fov / 2) * (M_PI / 180));
	c->mat_c2w = ft_getmat_c2w(c, ft_vset(0, 1, 0));
	if (ft_addback_object_list(cam, c, s))
		return (ft_destroy(c));
	return (success);
}
