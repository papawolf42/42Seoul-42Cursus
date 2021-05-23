/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console_numberof.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:16:21 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 12:17:33 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"
#include "object.h"

void			ft_console_numberof(t_ctrl *ctrl, t_object_type type)
{
	if (type == l)
		printf(TC_FORM_NUM_OF, ctrl->scene->idx_l + 1, ctrl->scene->count_l);
	else if (type == cam)
		printf(TC_FORM_NUM_OF, ctrl->scene->idx_c + 1, ctrl->scene->count_c);
}
