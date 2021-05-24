/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:53:01 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 16:38:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "struct.h"
#include "minirt.h"
#include "exit.h"

static void		ft_init_data(t_ctrl *ctrl)
{
	ctrl->mlx_ptr = mlx_init();
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
	static char		*str1 = "screenshot";
	char			*str2;
	static char		*str3 = ".bmp";
	char			str[42];

	ft_bzero(str, 42);
	ft_strlcpy(str, str1, 11);
	str2 = ft_itoa(num);
	if (str2 == NULL)
		return (fail);
	ft_strlcat(str, str2, 11);
	free(str2);
	ft_strlcat(str, str3, 20);
	*fd = open(str, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0744);
	if (*fd == -1)
		return (fail);
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
	close(fd);
	ft_exit(ctrl);
	return (success);
}
