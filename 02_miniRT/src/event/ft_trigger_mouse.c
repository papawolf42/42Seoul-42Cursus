/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigger_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:47:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 20:48:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"
#include "exit.h"

int			ft_trigger_mouse(int btn, int x, int y, t_ctrl *ctrl)
{
	int						idx;
	static t_pft_mouse		pft_event[] = {
		{BTN_LEFT, ft_select_object},
		// {BTN_LEFT, ft_deselect},
		{END, NUL}
	};

	idx = 0;
	while (pft_event[idx].btn != END && btn != pft_event[idx].btn)
		idx++;
	if (pft_event[idx].btn == END)
		return (false);
	return (pft_event[idx].event(ctrl, x, y));
}
