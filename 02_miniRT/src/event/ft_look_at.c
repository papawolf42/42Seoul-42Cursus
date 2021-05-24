/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:59:40 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 03:40:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"
#include "hit.h"
#include "object.h"

double			ft_theta_x(t_vec3 screen, t_vec3 normal)
{
	double		theta;

	screen.y = 0;
	screen = ft_vunit(screen);
	normal = ft_vscalar(normal, -1);
	theta = acos(ft_vdot(screen, normal));
	if (screen.x < 0)
		theta *= -1;
	return (theta);
}

double			ft_theta_y(t_vec3 screen, t_vec3 normal)
{
	double		theta;

	screen.x = 0;
	screen = ft_vunit(screen);
	normal = ft_vscalar(normal, -1);
	theta = acos(ft_vdot(screen, normal));
	if (screen.y > 0)
		theta *= -1;
	return (theta);
}

// static t_mat44				ft_getmat_c2w_rotate(t_camera *cam, t_vec3 axis_up)
// {
// 	t_vec3		up;
// 	t_vec3		right;
// 	t_vec3		forward;
// 	double		parallel;

// 	parallel = ft_vdot(cam->normal, axis_up);
// 	forward = ft_vscalar(cam->normal, -1);
// 	if (parallel == 1)
// 	{
// 		right = ft_vset(1, 0, 0);
// 		up = ft_vset(0, 0, -1);
// 	}
// 	else if (parallel == -1)
// 	{
// 		right = ft_vset(-1, 0, 0);
// 		up = ft_vset(0, 0, -1);
// 	}
// 	else
// 	{
// 		right = ft_vunit(ft_vcross(forward, axis_up));
// 		up = ft_vunit(ft_vcross(right, forward));
// 	}
// 	return (ft_mat_set(right, up, forward, cam->origin));
// }

int				ft_look_at(t_ctrl *c, int x, int y)
{
	t_vec3		screen;
	double		theta_x;
	double		theta_y;
	t_camera	*cam;
	t_vec3		axis;

	cam = ft_return_object(c->scene->camera_list, c->scene->idx_c);
	screen = ft_vunit(ft_switch_fisheye(c, cam->fov, x, y));
	theta_x = ft_theta_x(screen, cam->normal);
	theta_y = ft_theta_y(screen, cam->normal);
	axis = cam->mat_c2w.y;
	cam->mat_c2w = ft_mat_mult_rotate(ft_mat_rotate_y(theta_x), cam->mat_c2w);
	cam->mat_c2w = ft_mat_mult_rotate(ft_mat_rotate_x(theta_y), cam->mat_c2w);
	return (true);
}
