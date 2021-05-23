/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_mt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:51:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:08:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "console.h"

int				ft_toggle_mt(t_ctrl *ctrl)
{
	ctrl->bool_multi_threading = !ctrl->bool_multi_threading;
	ft_console_msg(ctrl, NUL);
	return (false);
}
