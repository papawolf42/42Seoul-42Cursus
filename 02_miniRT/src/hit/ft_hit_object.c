/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 00:46:26 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 11:58:31 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

t_bool		ft_hit_object(t_object_list *obj, t_ray *ray, t_hit_rec *rec)
{
	t_bool		bool_hit;

	bool_hit = false;
	if (obj->type == sp)
		bool_hit = ft_hit_sphere(obj->object, ray, rec);
	else if (obj->type == pl)
		bool_hit = ft_hit_plane(obj->object, ray, rec);
	else if (obj->type == sq)
		bool_hit = ft_hit_square(obj->object, ray, rec);
	else if (obj->type == cy)
		bool_hit = ft_hit_cylinder(obj->object, ray, rec);
	else if (obj->type == tr)
		bool_hit = ft_hit_triangle(obj->object, ray, rec);
	if (bool_hit == true)
		rec->object_list = obj;
	return (bool_hit);
}
