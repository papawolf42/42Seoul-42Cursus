/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:15:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

t_bool			ft_parse_light(t_scene *s, char **splits)
{
	t_light		*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 4)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(light));
	if (ft_parse_vector(&light->p, splits[1]))
		return (ft_destroy(light));
	if (ft_parse_real(&light->ratio, splits[2]))
		return (ft_destroy(light));
	if (ft_range_real(&light->ratio, 0, 1.0))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(light));
	if (ft_parse_color(&light->color, splits[3]))
		return (ft_destroy(light));
	if (ft_addback_object_list(l, light, s))
		return (ft_destroy(light));
	return (success);
}
