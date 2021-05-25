/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 09:11:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "mlx.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "parse.h"
#include "event.h"
#include "exit.h"
#include "object.h"

static t_bool	ft_init_ctrl(t_ctrl *ctrl)
{
	ft_bzero(ctrl, sizeof(t_ctrl));
	ctrl->mode = 'C';
	ctrl->bool_multi_threading = true;
	ctrl->bool_anti_aliasing = false;
	ctrl->bool_fish_eye = false;
	ctrl->unit_move = UNIT_MOVE;
	ctrl->unit_rotate = UNIT_ROTATE_DEGREE * (M_PI / 180.0);
	ctrl->unit_resize = UNIT_MOVE / 4;
	ctrl->mlx_ptr = mlx_init();
	ctrl->scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(ctrl->scene, sizeof(t_scene));
	if (ctrl->scene == NULL)
		return (ft_err_msg(ERR_MALLOC_FAIL));
	mlx_get_screen_size(ctrl->mlx_ptr, &ctrl->scene->canv.max_w,
													&ctrl->scene->canv.max_h);
	return (success);
}

int				main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	if (ft_init_ctrl(&ctrl))
		return (ft_exit(&ctrl));
	if (argc < 2 || 3 < argc)
		return (ft_err_msg(ERR_WRONG_NUMBERS_ARG));
	if (ft_is_endstr(argv[1], ".rt") == fail)
		return (ft_err_msg(ERR_2ND_ARG_NOT_END_RT) == fail);
	if (ft_parse_rt(&ctrl, argv[1]))
		return (ft_exit(&ctrl));
	if (argc == 2)
	{
		if (ft_minirt(&ctrl))
			return (ft_exit(&ctrl));
	}
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 8) == 0)
		ft_save_bmp(&ctrl, false);
	return (0);
}
