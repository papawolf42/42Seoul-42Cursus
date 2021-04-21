/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/21 23:45:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_read_rt(t_ctrl *ctrl, char *rt_file)
{
	ctrl->scene.width = 1024;
	ctrl->scene.height = 768;
	
	/* to avoid warning */
	rt_file = NULL;
	/* to avoid warning */
}