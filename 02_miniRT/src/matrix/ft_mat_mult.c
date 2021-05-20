/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:03:40 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 20:29:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat44				ft_mat_mult(t_mat44 r, t_mat44 c)
{
	t_mat44		rtn;

	rtn.x.x = r.x.x * c.x.x + r.x.y * c.y.x + r.x.z * c.z.x;
	rtn.x.y = r.x.x * c.x.y + r.x.y * c.y.y + r.x.z * c.z.y;
	rtn.x.z = r.x.x * c.x.z + r.x.y * c.y.z + r.x.z * c.z.z;
	rtn.y.x = r.y.x * c.x.x + r.y.y * c.y.x + r.y.z * c.z.x;
	rtn.y.y = r.y.x * c.x.y + r.y.y * c.y.y + r.y.z * c.z.y;
	rtn.y.z = r.y.x * c.x.z + r.y.y * c.y.z + r.y.z * c.z.z;
	rtn.z.x = r.z.x * c.x.x + r.z.y * c.y.x + r.z.z * c.z.x;
	rtn.z.y = r.z.x * c.x.y + r.z.y * c.y.y + r.z.z * c.z.y;
	rtn.z.z = r.z.x * c.x.z + r.z.y * c.y.z + r.z.z * c.z.z;
	rtn.trans.x = c.trans.x;
	rtn.trans.y = c.trans.y;
	rtn.trans.z = c.trans.z;
	rtn.scale = 1;
	return (rtn);
}