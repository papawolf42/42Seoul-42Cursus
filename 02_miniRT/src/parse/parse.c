/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/25 19:16:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

void		ft_read_rt(t_ctrl *ctrl, char *rt_file)
{
	ctrl->scene->width = 1024;
	ctrl->scene->height = 768;
	ctrl->scene->aspect_ratio = (double)1024 / (double)768;
	
	/* to avoid warning */
	rt_file = NULL;
	/* to avoid warning */
}