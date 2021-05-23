/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:42:22 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 19:13:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "minirt.h"
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

static void	ft_init_ctrl(t_ctrl *ctrl)
{
	ft_bzero(ctrl, sizeof(ctrl));
	ctrl->mode = 'C';
	ctrl->bool_multi_threading = true;
	ctrl->bool_anti_aliasing = false;
	ctrl->bool_fish_eye = false;
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
	{
		if (ft_minirt(&ctrl))
			return (ft_exit_minirt(&ctrl));
	}
	else if (argc == 3 && ft_strncmp(argv[3], "--save", 8) == 0)
		ft_save_bmp();
	return (0);
}
