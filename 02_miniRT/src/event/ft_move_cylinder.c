/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:04:45 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:47:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "parse.h"

int				ft_move_cylinder(t_object_list *list, t_vec3 trans)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)list->object;
	cylinder->center_bottom = ft_vplus(cylinder->center_bottom, trans);
	ft_cylinder_set(cylinder, false);
	return (0);
}
