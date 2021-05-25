/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:53:01 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 14:58:54 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "struct.h"
#include "minirt.h"
#include "exit.h"
#include "utils.h"

static void		ft_init_data(t_ctrl *ctrl)
{
	ctrl->img.img_ptr = mlx_new_image(ctrl->mlx_ptr,
										ctrl->scene->canv.width,
										ctrl->scene->canv.height);
	ctrl->img.data = mlx_get_data_addr(ctrl->img.img_ptr,
										&ctrl->img.bit_per_pixel,
										&ctrl->img.size_line,
										&ctrl->img.endian);
}

static t_bool	ft_open(int *fd)
{
	static int		num;
	static char		*str1 = "output_bmp/screenshot";
	char			*str2;
	static char		*str3 = ".bmp";
	char			str[42];

	ft_bzero(str, 42);
	ft_strcpy(str, str1);
	str2 = ft_itoa(num);
	if (str2 == NULL)
		return (fail);
	ft_strcat(str, str2);
	free(str2);
	ft_strcat(str, str3);
	*fd = open(str, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0744);
	if (*fd == -1)
		return (fail);
	num++;
	return (success);
}

static t_bool	ft_close(int fd)
{
	if (fd != -1)
		close(fd);
	return (fail);
}

t_bool			ft_save_bmp(t_ctrl *ctrl, t_bool bool_minirt)
{
	int		fd;

	fd = 0;
	if (bool_minirt == false)
		ft_init_data(ctrl);
	if (ft_open(&fd))
		return (ft_close(fd));
	if (ft_switch(ctrl))
		return (ft_close(fd));
	ft_write_bmp(ctrl, fd);
	if (bool_minirt == false)
	{
		close(fd);
		ft_exit(ctrl);
	}
	return (success);
}
