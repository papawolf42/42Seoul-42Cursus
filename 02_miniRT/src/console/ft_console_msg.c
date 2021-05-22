/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:32:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 17:57:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "struct.h"

static void		ft_print_mode(char mode)
{
	if (mode == 'L')
		printf("[\033[1;32mmode\033[0m] Light\n");
	if (mode == 'C')
		printf("[\033[1;32mmode\033[0m] Camera\n");
	if (mode == 'O')
		printf("[\033[1;32mmode\033[0m] Object\n");
}

void			ft_console_msg(t_ctrl *ctrl, char *message)
{
	printf("\033[1J\n");
	printf("███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗\n");
	printf("████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝\n");
	printf("██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║   \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║   \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║   \n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝   \n");
	printf("translate  rotate\n");
	printf("┌──┬──┬──┐ ┌──┬──┬──┐ ┌─────────────┐\n");
	printf("│Q │W │E │ │R │T │Y │ │ 1. AA : on  │\n");
	printf("├──┼──┼──┤ ├──┼──┼──┤ │ 2. MT : off │\n");
	printf("│A │S │D │ │F │G │H │ │ 3. FE : off │\n");
	printf("└──┴──┴──┘ └──┴──┴──┘ └─────────────┘\n");
	printf("This is instruction\n");
	ft_print_mode(ctrl->mode);
	printf("[\033[1;32mminiRT\033[0m]: %s\n", message);
}

	// printf("┌──┬──┬──┐ ┌──┬──┬──┐\n");
	// printf("│Q⨀│W↑│E⨂│ │R⟲│T↑│Y⟳│\n");
	// printf("├──┼──┼──┤ ├──┼──┼──┤\n");
	// printf("│A←│S↓│D→│ │F←│G↓│H→│\n");
	// printf("└──┴──┴──┘ └──┴──┴──┘\n");