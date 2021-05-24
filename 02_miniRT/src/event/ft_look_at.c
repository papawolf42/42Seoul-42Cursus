/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:59:40 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 08:34:58 by gunkim           ###   ########.fr       */
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
