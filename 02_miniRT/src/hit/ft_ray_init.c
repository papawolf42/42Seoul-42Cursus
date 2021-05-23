/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:51:16 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 15:22:06 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_point3	ft_screen(t_ctrl *c, double fov, int x, int y)
{
	t_point3	screen;

	screen.x = (2 * ((x + 0.5) / c->scene->canv.width) - 1) * fov
				* c->scene->canv.aspect_ratio;
	screen.y = (-2 * ((y + 0.5) / c->scene->canv.height) + 1) * fov;
	screen.z = -1;
	return (screen);
}

t_point3	ft_screen_fisheye(t_ctrl *c, double fov, int x, int y)
{
	t_point3	screen;

	screen.x = (2 * ((x + 0.5) / c->scene->canv.width) - 1);
	screen.x *= INDEX_FISH_EYE;
	screen.y = (-2 * ((y + 0.5) / c->scene->canv.height) + 1);
	screen.y *= INDEX_FISH_EYE;
	screen.z = -1;
	screen.z *= sqrt(1 - screen.x * screen.x - screen.y * screen.y);
	screen.x *= fov * c->scene->canv.aspect_ratio;
	screen.y *= fov;
	return (screen);
}


t_point3	ft_switch_fisheye(t_ctrl *c, double fov, int x, int y)
{
	if (c->bool_fish_eye == false)
		return (ft_screen(c, fov, x, y));
	return (ft_screen_fisheye(c, fov, x, y));
}

t_ray		ft_ray_init(t_ctrl *c, t_camera *cam, int x, int y)
{
	t_ray		ray;
	t_canvas	*canv;
	t_point3	screen;

	canv = &c->scene->canv;
	screen = ft_switch_fisheye(c, cam->fov, x, y);
	ray.org = cam->mat_c2w.trans;
	ray.dir = V_MINUS(ft_linear_transform(cam->mat_c2w, screen), ray.org);
	return (ray);
}
