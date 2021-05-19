/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:32:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 22:51:14 by gunkim           ###   ########.fr       */
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
	printf("This is instruction\n");
	ft_print_mode(ctrl->mode);
	printf("[\033[1;32mminiRT\033[0m]: %s\n", message);
}
