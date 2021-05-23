/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigger_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:56:04 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 16:39:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"
#include "exit.h"

int			ft_trigger_key(t_ctrl *ctrl, int key)
{
	int						idx;
	static t_pft_key		pft_event[] = {
		{KEY_ESC, ft_exit_minirt}, {KEY_W, ft_move_up}, {KEY_S, ft_move_down},
		{KEY_A, ft_move_left}, {KEY_D, ft_move_right}, {KEY_Q, ft_move_back},
		{KEY_E, ft_move_forward}, {KEY_T, ft_pitch_up}, {KEY_G, ft_pitch_down},
		{KEY_F, ft_yaw_left}, {KEY_H, ft_yaw_right}, {KEY_R, ft_roll_left},
		{KEY_Y, ft_roll_right}, {KEY_4, ft_mode_light}, {KEY_5, ft_mode_camera},
		{KEY_MINUS, ft_list_before}, {KEY_EQUAL, ft_list_after},
		{KEY_1, ft_toggle_mt},
		{KEY_2, ft_toggle_aa},
		{KEY_3, ft_toggle_fe},
		{END, NUL}
	};

	idx = 0;
	while (pft_event[idx].key != END && pft_event[idx].key != key)
		idx++;
	if (pft_event[idx].key == END)
		return (false);
	return (pft_event[idx].event(ctrl));
}
