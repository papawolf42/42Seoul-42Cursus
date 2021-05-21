/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mult_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:10:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 18:50:47 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat44				ft_mat_mult_rotate(t_mat44 r, t_mat44 c)
{
	t_mat44		rtn;

	rtn.x = ft_linear_transform_rotate(r, c.x);
	rtn.y = ft_linear_transform_rotate(r, c.y);
	rtn.z = ft_linear_transform_rotate(r, c.z);
	rtn.trans.x = c.trans.x;
	rtn.trans.y = c.trans.y;
	rtn.trans.z = c.trans.z;
	rtn.scale = 1;
	return (ft_mat_set(rtn.x, rtn.y, rtn.z, rtn.trans));
}
