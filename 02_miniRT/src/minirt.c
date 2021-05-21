/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 00:40:07 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"
#include "object.h"
#include "hit.h"
#include "event.h"
#include "exit.h"

/*
** t_vec3		ft_get_point(t_point3 org, t_vec3 dir, double t)
** {
** 	return (V_PLUS(org, V_SCALAR(dir, t)));
** }
** mlx_hook(ctrl->win_ptr, EVENT_BUTTONPRESS, (1L<<2),
** ft_get_position_clicked, ctrl->scene);
*/

/*
**			if ((x == 129) && (y == 367))
**			{
**				ray.org.x = 1;
**			}
*/

t_bool		ft_render(t_ctrl *c)
{
	t_var_render	v;

	v.camera = (t_camera *)ft_return_object(c->scene->camera_list,
											c->scene->idx_c);
	v.y = 0;
	while (v.y < c->scene->canv.height)
	{
		v.x = 0;
		while (v.x < c->scene->canv.width)
		{
			v.ray = ft_ray_init(&c->scene->canv, v.camera, v.x, v.y);
			v.color = ft_ray_to_color(v.ray, c);
			v.data = c->img.data + (v.y * c->img.size_line +
									v.x * (c->img.bit_per_pixel / 8));
			*(unsigned int *)v.data = ft_rgb_to_data(v.color);
			v.x++;
		}
		v.y++;
	}
	return (success);
}

/*
** static int	ft_get_position_clicked(int click, int x, int y, t_scene *s)
** {
** 	(void)click;
** 	(void)s->canv.height;
** 	printf("x:%d, y:%d\n", x, y);
** 	return (0);
** }
*/

void		ft_minirt(t_ctrl *ctrl)
{
	ctrl->mlx_ptr = mlx_init();
	ctrl->win_ptr = mlx_new_window(ctrl->mlx_ptr,
									ctrl->scene->canv.width,
									ctrl->scene->canv.height,
									"miniRT");
	ctrl->img.img_ptr = mlx_new_image(ctrl->mlx_ptr,
										ctrl->scene->canv.width,
										ctrl->scene->canv.height);
	ctrl->img.data = mlx_get_data_addr(ctrl->img.img_ptr,
										&ctrl->img.bit_per_pixel,
										&ctrl->img.size_line,
										&ctrl->img.endian);
	ft_render(ctrl);
	mlx_put_image_to_window(ctrl->mlx_ptr,
							ctrl->win_ptr,
							ctrl->img.img_ptr, 0, 0);
	ft_init_hook(ctrl);
}

static void	ft_init_ctrl(t_ctrl *ctrl)
{
	ft_bzero(ctrl, sizeof(ctrl));
	ctrl->mode = 'C';
}

static void	ft_save_bmp(void)
{
}

int			main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	ft_init_ctrl(&ctrl);
	if (argc < 2 || 3 < argc)
		return (ft_err_msg(ERR_WRONG_NUMBERS_ARG));
	if (ft_is_endstr(argv[1], ".rt") == fail)
		return (ft_err_msg(ERR_2ND_ARG_NOT_END_RT) == fail);
	if (ft_parse_rt(&ctrl, argv[1]))
		return (ft_exit_minirt(&ctrl));
	if (argc == 2)
		ft_minirt(&ctrl);
	else if (argc == 3 && ft_strncmp(argv[3], "--save", 8) == 0)
		ft_save_bmp();
	return (0);
}
