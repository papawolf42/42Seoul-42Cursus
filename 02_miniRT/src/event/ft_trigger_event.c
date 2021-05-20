/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigger_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:56:04 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:30:50 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "struct.h"
#include "event.h"
#include "exit.h"

/*
** https://en.wikipedia.org/wiki/Flight_control_surfaces
*/
int			ft_trigger_event(t_ctrl *ctrl, int key)
{
	int						idx;
	static t_trigger_event	pft_event[] = {
		{KEY_ESC, ft_exit_minirt},
		// {KEY_TAB, ft_next_list},

		{KEY_W, ft_move_up},
		{KEY_S, ft_move_down},
		{KEY_A, ft_move_left},
		{KEY_D, ft_move_right},
		{KEY_Q, ft_move_back},
		{KEY_E, ft_move_forward},
		{KEY_I, ft_pitch_up},
		{KEY_K, ft_pitch_down},
		{KEY_J, ft_yaw_left},
		{KEY_L, ft_yaw_right},
		{KEY_U, ft_roll_left},
		{KEY_O, ft_roll_right},

		{KEY_L, ft_mode_light},
		{KEY_C, ft_mode_camera},
		// {KEY_O, ft_mode_object},

		// {KEY_1, ft_list_one},
		// {KEY_2, ft_list_two},
		// {KEY_3, ft_list_three},
		// {KEY_4, ft_list_four},
		// {KEY_5, ft_list_five},
		// {KEY_6, ft_list_six},
		// {KEY_7, ft_list_seven},
		// {KEY_8, ft_list_eight},
		// {KEY_9, ft_list_nine},
		// {KEY_0, ft_list_ten},

		{KEY_MINUS, ft_list_before},
		{KEY_EQUAL, ft_list_after},
		{NO_KEY, NUL}
	};

	idx = 0;
	while (pft_event[idx].key != NO_KEY && key != pft_event[idx].key)
		idx++;
	if (pft_event[idx].key == NO_KEY)
		return (false);
	return (pft_event[idx].event(ctrl));
}