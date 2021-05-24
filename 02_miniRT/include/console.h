/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:09:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 01:54:04 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_H
# define CONSOLE_H

# include <stdio.h>
# include "struct.h"

/*
** TC stand for Terminal Control
*/
# define TC_LOGO_1			"███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗\n"
# define TC_LOGO_2			"████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝\n"
# define TC_LOGO_3			"██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║   \n"
# define TC_LOGO_4			"██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║   \n"
# define TC_LOGO_5			"██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║   \n"
# define TC_LOGO_6			"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝   \n"

# define TC_STATUS_0		"translate  rotate\n"
# define TC_STATUS_1		"┌──┬──┬──┐ ┌──┬──┬──┐ ┌─────────────┐\n"
# define TC_STATUS_2_1		"│Q∙│W↑│E×│ │R↶│T↑│Y↷│ │ 1. MT : "
# define TC_STATUS_3_1		"├──┼──┼──┤ ├──┼──┼──┤ │ 2. AA : "
# define TC_STATUS_4_1		"│A←│S↓│D→│ │F←│G↓│H→│ │ 3. FE : "
# define TC_STATUS_CLOSE									   " │\n"
# define TC_STATUS_5		"└──┴──┴──┘ └──┴──┴──┘ └─────────────┘\n"
# define TC_STATUS_6		"filter     resize     before/after\n"
# define TC_STATUS_7		"┌─────────┐   ┌──┐    ┌──┬──┐\n"
# define TC_STATUS_8_1		"│tab "
# define TC_STATUS_8_2		"│   │↑ │    │- │+ │\n"
# define TC_STATUS_9		"└─────────┘┌──┼──┼──┐ └──┴──┘\n"
# define TC_STATUS_10		"           │← │↓ │→ │\n"
# define TC_STATUS_11		"           └──┴──┴──┘\n"
# define TC_STATUS_ON		"on "
# define TC_STATUS_OFF		"off"

# define TC_MODE_LIGHT		"[4] Light mode"
# define TC_MODE_CAMERA		"[5] Camera mode"
# define TC_MODE_OBJECT		"[Click] Object mode"

# define TC_RESET			"\033[0m"
# define TC_BOLD			"\033[1m"
# define TC_DIM				"\033[2m"
# define TC_INVERT			"\033[7m"

# define TC_RED				"\033[31m"
# define TC_GREEN			"\033[32m"
# define TC_BLUE			"\033[34m"
# define TC_BYELLOW			"\033[93m"

# define TC_ERASE_UP		"\033[1J"

# define TC_FORM_10			"%s%-10s%s\n"
# define TC_FORM_10_NOFL	"%s%-10s%s"
# define TC_FORM_NUM_OF		"%d of %d\n"

# define TC_TYPE			"type"
# define TC_POINT			"point"
# define TC_NORMAL			"normal"
# define TC_AXIS			"axis"
# define TC_COLOR			"color"
# define TC_RATIO			"ratio"
# define TC_RADIUS			"radius"
# define TC_SIDE_LEN		"side len"
# define TC_HEIGHT			"height"
# define TC_FOV				"FOV"

# define TC_LIGHT			"light"
# define TC_CAMERA			"camera"
# define TC_SPHERE			"sphere"
# define TC_PLANE			"plane"
# define TC_SQUARE			"square"
# define TC_CYLINDER		"cylinder"
# define TC_TRIANGLE		"triangle"

typedef struct s_pft_console	t_pft_console;

struct			s_pft_console
{
	t_object_type	type;
	void			(*console)(t_ctrl *ctrl);
};

void			ft_console_msg(t_ctrl *ctrl, char *message);
void			ft_console_clear(void);
void			ft_console_logo(void);
void			ft_console_status(t_ctrl *ctrl);
void			ft_console_mode_and_object(t_ctrl *ctrl);

void			ft_console_object(t_ctrl *ctrl, t_object_type type);
void			ft_console_sphere(t_ctrl *ctrl);
void			ft_console_plane(t_ctrl *ctrl);
void			ft_console_square(t_ctrl *ctrl);
void			ft_console_cylinder(t_ctrl *ctrl);
void			ft_console_triangle(t_ctrl *ctrl);
void			ft_console_light(t_ctrl *ctrl);
void			ft_console_camera(t_ctrl *ctrl);

void			ft_console_type(t_object_type type);
void			ft_console_numberof(t_ctrl *ctrl, t_object_type type);
void			ft_console_real(char *title, double real);
void			ft_console_vec(char *title, t_vec3 vec);
void			ft_console_color(t_color color);

#endif
