/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 03:04:55 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 12:15:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_type(t_object_type type)
{
	if (type == l)
		printf(TC_FORM_10_NOFL, TC_BLUE, TC_LIGHT, TC_RESET);
	if (type == cam)
		printf(TC_FORM_10_NOFL, TC_BLUE, TC_CAMERA, TC_RESET);
	if (type == sp)
		printf(TC_FORM_10, TC_BLUE, TC_SPHERE, TC_RESET);
	if (type == pl)
		printf(TC_FORM_10, TC_BLUE, TC_PLANE, TC_RESET);
	if (type == sq)
		printf(TC_FORM_10, TC_BLUE, TC_SQUARE, TC_RESET);
	if (type == cy)
		printf(TC_FORM_10, TC_BLUE, TC_CYLINDER, TC_RESET);
	if (type == tr)
		printf(TC_FORM_10, TC_BLUE, TC_TRIANGLE, TC_RESET);
}
