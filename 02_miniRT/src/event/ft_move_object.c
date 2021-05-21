/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:11:15 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 19:03:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "parse.h"

int				ft_move_object(t_object_list *list, t_vec3 trans)
{
	t_object_var	objs;

	if (list->type == sp)
	{
		objs.sphere = (t_sphere *)list->object;
		objs.sphere->center = V_PLUS(objs.sphere->center, trans);
	}
	else if (list->type == pl)
	{
		objs.plane = (t_plane *)list->object;
		objs.plane->point = V_PLUS(objs.plane->point, trans);
	}
	else if (list->type == sq)
	{
		objs.square = (t_square *)list->object;
		objs.square->center = V_PLUS(objs.square->center, trans);
		ft_square_set(objs.square);
	}
	else if (list->type == cy)
	{
		objs.cylinder = (t_cylinder *)list->object;
		objs.cylinder->center_bottom = V_PLUS(objs.cylinder->center_bottom, trans);
		ft_cylinder_set(objs.cylinder);
	}
	else if (list->type == tr)
	{
		objs.trinagle = (t_triangle *)list->object;
		objs.trinagle->a = V_PLUS(objs.trinagle->a, trans);
		objs.trinagle->b = V_PLUS(objs.trinagle->b, trans);
		objs.trinagle->b = V_PLUS(objs.trinagle->c, trans);
		ft_triangle_set(objs.trinagle);
	}
	return (0);
}