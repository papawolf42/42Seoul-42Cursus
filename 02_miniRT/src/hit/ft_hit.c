/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:02:45 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 00:47:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "hit.h"

t_bool				ft_hit(t_object_list *obj, t_ray *ray, t_hit_rec *rec)
{
	t_bool		bool_hit;

	bool_hit = false;
	while (obj)
	{
		if (ft_hit_object(obj, ray, rec))
		{
			bool_hit = true;
			rec->t_max = rec->t;
		}
		obj = obj->next;
	}
	return (bool_hit);
}