/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:15:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 13:04:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "error.h"
#include "utils.h"
#include "parse.h"

t_bool			ft_parse_light(t_scene *s, char **splits)
{
	t_light		*l;

	l = (t_light *)malloc(sizeof(t_light));
	if (l == NUL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	if (ft_strslen(splits) != 4)
		return (ft_err_msg(ERR_WORNG_ARG) && ft_destroy(l));
	if (ft_parse_vector(&l->p, splits[1]))
		return (ft_destroy(l));
	if (ft_parse_real(&l->ratio, splits[2]))
		return (ft_destroy(l));
	if (ft_range_real(&l->ratio, 0, 1.0))
		return (ft_err_msg(ERR_BAD_RANGE) && ft_destroy(l));
	if (ft_parse_color(&l->color, splits[3]))
		return (ft_destroy(l));
	ft_object_list(cam, l, s->light_list);
	return (success);
}
