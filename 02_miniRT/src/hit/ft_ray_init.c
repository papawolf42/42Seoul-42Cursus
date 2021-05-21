/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:51:16 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 21:51:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_ray		ft_ray_init(t_canvas *canv, t_camera *cam, int x, int y)
{
	t_ray		ray;
	t_point3	screen;

	screen.x = (2 * ((x + 0.5) / canv->width) - 1);
	screen.x *= FISH_EYE_INDEX;// FISH_EYE
	screen.y = (-2 * ((y + 0.5) / canv->height) + 1);
	screen.y *= FISH_EYE_INDEX;// FISH_EYE
	screen.z = -1;
	screen.z *= sqrt(1 - screen.x * screen.x - screen.y * screen.y);// FISH_EYE
	screen.x *= cam->fov * canv->aspect_ratio;
	screen.y *= cam->fov;
	ray.org = cam->mat_c2w.trans;
	ray.dir = V_MINUS(ft_linear_transform(cam->mat_c2w, screen), ray.org);
	return (ray);
}
