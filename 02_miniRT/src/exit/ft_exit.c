/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:56:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:10:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "alias.h"
#include "struct.h"
#include "exit.h"

int				ft_exit(t_ctrl *ctrl)
{
	ft_destroy_mlx(ctrl);
	ft_free_scene(ctrl->scene);
	exit(1);
	return (fail);
}
