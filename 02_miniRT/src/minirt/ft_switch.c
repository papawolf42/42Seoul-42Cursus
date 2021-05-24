/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:05:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 19:14:25 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			ft_switch(t_ctrl *ctrl)
{
	t_bool		bool_err;

	bool_err = success;
	if (ctrl->bool_multi_threading == false)
	{
		if (ctrl->bool_anti_aliasing == false)
			ft_render(ctrl);
		else
			ft_render_aa(ctrl);
	}
	else
	{
		if (ctrl->bool_anti_aliasing == false)
			bool_err = ft_render_multi_thread(ctrl);
		else
			bool_err = ft_render_mt_aa(ctrl);
	}
	return (bool_err);
}
