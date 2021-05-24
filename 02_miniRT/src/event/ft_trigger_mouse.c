/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigger_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:47:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 02:21:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "alias.h"
#include "struct.h"
#include "event.h"
#include "exit.h"
#include "minirt.h"
#include "error.h"

int			ft_trigger_mouse(int btn, int x, int y, t_ctrl *ctrl)
{
	int						idx;
	static t_pft_mouse		pft_event[] = {
		{BTN_LEFT, ft_select_object},
		{BTN_RIGHT, ft_look_at},
		{END, NULL}
	};

	idx = 0;
	while (pft_event[idx].btn != END && pft_event[idx].btn != btn)
		idx++;
	if (pft_event[idx].btn == END)
		return (false);
	return (pft_event[idx].event(ctrl, x, y));
}
