/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:05:27 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:47:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "parse.h"

int				ft_move_triangle(t_object_list *list, t_vec3 trans)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)list->object;
	triangle->a = ft_vplus(triangle->a, trans);
	triangle->b = ft_vplus(triangle->b, trans);
	triangle->c = ft_vplus(triangle->c, trans);
	ft_triangle_set(triangle);
	return (0);
}
