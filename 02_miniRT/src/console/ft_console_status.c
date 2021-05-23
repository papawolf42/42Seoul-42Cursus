/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:45:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 23:43:17 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

static void		ft_status_refer(int boolean)
{
	if (boolean == true)
		printf("%s%s%s", TC_GREEN, TC_STATUS_ON, TC_RESET);
	else if (boolean == false)
		printf("%s%s%s", TC_RED, TC_STATUS_OFF, TC_RESET);
}

static void		ft_status_switch(t_ctrl *ctrl, int line)
{
	if (line == 2)
		ft_status_refer(ctrl->bool_multi_threading);
	if (line == 3)
		ft_status_refer(ctrl->bool_anti_aliasing);
	if (line == 4)
		ft_status_refer(ctrl->bool_fish_eye);
}

void			ft_console_status(t_ctrl *ctrl)
{
	printf("translate  rotate\n");
	printf("%s", TC_STATUS_1);
	printf("%s", TC_STATUS_2_1);
	ft_status_switch(ctrl, 2);
	printf("%s", TC_STATUS_CLOSE);
	printf("%s", TC_STATUS_3_1);
	ft_status_switch(ctrl, 3);
	printf("%s", TC_STATUS_CLOSE);
	printf("%s", TC_STATUS_4_1);
	ft_status_switch(ctrl, 4);
	printf("%s", TC_STATUS_CLOSE);
	printf("%s", TC_STATUS_5);
}
