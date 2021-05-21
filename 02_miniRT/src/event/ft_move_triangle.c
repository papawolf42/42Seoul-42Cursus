/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:05:27 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 02:08:51 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "parse.h"

int				ft_move_triangle(t_object_list *list, t_vec3 trans)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)list->object;
	triangle->a = V_PLUS(triangle->a, trans);
	triangle->b = V_PLUS(triangle->b, trans);
	triangle->c = V_PLUS(triangle->c, trans);
	ft_triangle_set(triangle);
	return (0);
}
