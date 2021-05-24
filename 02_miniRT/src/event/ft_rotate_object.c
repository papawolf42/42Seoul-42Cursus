/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:25:13 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 11:28:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "parse.h"
#include "event.h"

int				ft_rotate_object(t_object_list *list, t_mat44 mat)
{
	int						idx;
	static t_pft_rotate		pft_rotate[] = {
		{pl, ft_rotate_plane},
		{sq, ft_rotate_square},
		{cy, ft_rotate_cylinder},
		{no, NULL}
	};

	idx = 0;
	while (pft_rotate[idx].type != no && pft_rotate[idx].type != list->type)
		idx++;
	if (pft_rotate[idx].type == no)
		return (false);
	return (pft_rotate[idx].rotate(list, mat));
}
