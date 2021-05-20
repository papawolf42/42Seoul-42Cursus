/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:12:14 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/18 17:12:14 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "alias.h"
# include "struct.h"

# define MASK_KEYPRESS		1L<<0
# define MASK_KEYRELEASE	1L<<1
# define MASK_BUTTONPRESS	1L<<2
# define MASK_EXITWINDOW	1L<<2

# define EVENT_KEYPRESS		2
# define EVENT_KEYRELEASE	3
# define EVENT_BUTTONPRESS	4
# define EVENT_EXIT_WINDOW	17

# define NO_KEY				-1

/*
** Keyboard LETTERS
*/

# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16
# define KEY_U				32
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_V				9
# define KEY_B				11
# define KEY_N				45
# define KEY_M				46

/*
** Keyboard ARROWS
*/

# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126

/*
** Keyboard NUM
*/

# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29
# define KEY_MINUS			27
# define KEY_EQUAL			24

/*
** Keyboard MISC
*/

# define KEY_SP 49
# define KEY_ESC 53
# define KEY_TAB 48

/*
** unit
*/

void			ft_console_msg(t_ctrl *ctrl, char *message);

void			ft_init_hook(t_ctrl *ctrl);

int				ft_handle_key(int key, t_ctrl *ctrl);
int				ft_trigger_event(t_ctrl *ctrl, int key);

int				ft_mode_light(t_ctrl *ctrl);
int				ft_mode_camera(t_ctrl *ctrl);
int				ft_mode_object(t_ctrl *ctrl);

int				ft_list_before(t_ctrl *ctrl);
int				ft_list_after(t_ctrl *ctrl);

int				ft_move_forward(t_ctrl *ctrl);
int				ft_move_back(t_ctrl *ctrl);
int				ft_move_left(t_ctrl *ctrl);
int				ft_move_right(t_ctrl *ctrl);
int				ft_move_down(t_ctrl *ctrl);
int				ft_move_up(t_ctrl *ctrl);

int				ft_pitch_up(t_ctrl *ctrl);
int				ft_pitch_down(t_ctrl *ctrl);
int				ft_yaw_left(t_ctrl *ctrl);
int				ft_yaw_right(t_ctrl *ctrl);
int				ft_roll_right(t_ctrl *ctrl);
int				ft_roll_left(t_ctrl *ctrl);


typedef struct s_trigger_event	t_trigger_event;

struct			s_trigger_event
{
	int			key;
	int			(*event)(t_ctrl *ctrl);
};

#endif
