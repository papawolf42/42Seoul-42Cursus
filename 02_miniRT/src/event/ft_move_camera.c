/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 01:18:01 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 01:23:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "parse.h"
#include "object.h"

int				ft_move_camera(t_camera *cam, t_vec3 trans)
{
	cam->mat_c2w.trans = V_PLUS(cam->mat_c2w.trans, trans);
	return (0);
}
