/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:37:37 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 16:37:46 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "console.h"

int				ft_toggle_aa(t_ctrl *ctrl)
{
	ctrl->bool_anti_aliasing = !ctrl->bool_anti_aliasing;
	ft_console_msg(ctrl, NUL);
	return (true);
}
