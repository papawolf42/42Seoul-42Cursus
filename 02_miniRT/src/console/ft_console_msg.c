/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:32:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 23:42:47 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"
#include "console.h"

void			ft_console_msg(t_ctrl *ctrl, char *message)
{
	ft_console_clear();
	ft_console_logo();
	printf("\n");
	ft_console_status(ctrl);
	printf("\n");
	ft_console_mode_and_object(ctrl);
	if (message != NUL)
		printf("[\033[1;32mminiRT\033[0m]: %s\n", message);
}

	// printf("┌──┬──┬──┐ ┌──┬──┬──┐\n");
	// printf("│Q⨀│W↑│E⨂│ │R⟲│T↑│Y⟳│\n");
	// printf("├──┼──┼──┤ ├──┼──┼──┤\n");
	// printf("│A←│S↓│D→│ │F←│G↓│H→│\n");
	// printf("└──┴──┴──┘ └──┴──┴──┘\n");