/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:24:50 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 18:23:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "matrix.h"

// t_mat44	ft_mat_set(t_vec3 right, t_vec3 up, t_vec3 forward, t_vec3 origin)
// {
// 	t_mat44		mat;

// 	mat.data[0][0] = right.x;
// 	mat.data[0][1] = right.y;
// 	mat.data[0][2] = right.z;
// 	mat.data[0][3] = 0;
// 	mat.data[0][0] = up.x;
// 	mat.data[0][1] = up.y;
// 	mat.data[0][2] = up.z;
// 	mat.data[0][3] = 0;
// 	mat.data[0][0] = forward.x;
// 	mat.data[0][1] = forward.y;
// 	mat.data[0][2] = forward.z;
// 	mat.data[0][3] = 0;
// 	mat.data[0][0] = origin.x;
// 	mat.data[0][1] = origin.y;
// 	mat.data[0][2] = origin.z;
// 	mat.data[0][3] = 0;
// 	return (mat);
// }

t_mat44				ft_mat_set(t_vec3 x, t_vec3 y, t_vec3 z, t_vec3 trans)
{
	t_mat44         mat;

	mat.x = x;
	mat.y = y;
	mat.z = z;
	mat.trans = trans;
	mat.scale = 0;
	return (mat);
}

t_mat44				ft_getmat_c2w(t_camera *cam, t_vec3 axis_up)
{
	t_vec3		up;
	t_vec3		right;
	t_vec3		forward;
	double		parallel;

	parallel = V_DOT(cam->normal, axis_up);
	forward = V_SCALAR(cam->normal, -1);
	// forward = cam->normal;
	if (parallel == 1)
	{
		right = V_SET(1, 0, 0);
		up = V_SET(0, 0, -1);
	}
	else if (parallel == -1)
	{
		right = V_SET(-1, 0, 0);
		up = V_SET(0, 0, -1);
	}
	else
	{
		right = V_UNIT(V_CROSS(forward, axis_up));
		up = V_UNIT(V_CROSS(right, forward));
		// right = V_UNIT(V_CROSS(axis_up, forward));
		// up = V_UNIT(V_CROSS(forward, right));
	}
	return (ft_mat_set(right, up, forward, cam->origin));
}

t_vec3		ft_linear_transform(t_mat44 mat, t_vec3 vec)
{
	t_vec3		rtn;

	rtn.x = mat.x.x * vec.x + mat.x.y * vec.y + mat.x.z * vec.z + mat.trans.x;
	rtn.y = mat.y.x * vec.x + mat.y.y * vec.y + mat.y.z * vec.z + mat.trans.y;
	rtn.z = mat.z.x * vec.x + mat.z.y * vec.y + mat.z.z * vec.z + mat.trans.z;
	return (rtn);
}

t_vec3		ft_linear_transform_rotate(t_mat44 mat, t_vec3 vec)
{
	t_vec3		rtn;

	rtn.x = mat.x.x * vec.x + mat.x.y * vec.y + mat.x.z * vec.z;
	rtn.y = mat.y.x * vec.x + mat.y.y * vec.y + mat.y.z * vec.z;
	rtn.z = mat.z.x * vec.x + mat.z.y * vec.y + mat.z.z * vec.z;
	return (rtn);
}
