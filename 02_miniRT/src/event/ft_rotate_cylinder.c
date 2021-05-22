/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:02:31 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 09:02:53 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "parse.h"

int				ft_rotate_cylinder(t_object_list *list, t_mat44 mat)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)list->object;
	cylinder->axis = ft_linear_transform_rotate(mat, cylinder->axis);
	ft_cylinder_set(cylinder);
	return (0);
}
