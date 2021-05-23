/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:11:15 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:09:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "parse.h"
#include "event.h"

int				ft_move_object(t_object_list *list, t_vec3 trans)
{
	int						idx;
	static t_pft_move		pft_move[] = {
		{sp, ft_move_sphere},
		{pl, ft_move_plane},
		{sq, ft_move_square},
		{cy, ft_move_cylinder},
		{tr, ft_move_triangle},
		{no, NUL}
	};

	idx = 0;
	while (pft_move[idx].type != no && pft_move[idx].type != list->type)
		idx++;
	if (pft_move[idx].type == no)
		return (false);
	return (pft_move[idx].move(list, trans));
}
