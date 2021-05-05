/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:53:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/04 17:42:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "struct.h"

t_triangle		*ft_triangle(t_point3 a, t_point3 b, t_point3 c, t_color color)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	triangle->ab = V_MINUS(b, a);
	triangle->bc = V_MINUS(c, b);
	triangle->ca = V_MINUS(a, c);
	triangle->normal = V_UNIT(V_CROSS(triangle->ab, triangle->bc));
	triangle->color = color;
	return (triangle);
}