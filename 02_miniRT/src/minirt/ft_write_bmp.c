/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:32:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 00:33:37 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "alias.h"
#include "libft.h"

static void		ft_write_bmp_header(t_ctrl *ctrl, int fd)
{
	t_uchar		bmp_h[14];
	int			size_file;

	ft_bzero(bmp_h, 14);
	size_file = 4 * ctrl->scene->canv.width * ctrl->scene->canv.height + 54;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = (t_uchar)size_file;
	bmp_h[3] = (t_uchar)(size_file >> 8);
	bmp_h[4] = (t_uchar)(size_file >> 16);
	bmp_h[5] = (t_uchar)(size_file >> 24);
	bmp_h[10] = 54;
	write(fd, bmp_h, 14);
}

static void		ft_write_dib_header(t_ctrl *ctrl, int fd)
{
	t_uchar		dib_h[40];
	int			size_file;

	ft_bzero(dib_h, 40);
	size_file = 4 * ctrl->scene->canv.width * ctrl->scene->canv.height + 54;
	dib_h[0] = 40;
	dib_h[4] = (t_uchar)ctrl->scene->canv.width;
	dib_h[5] = (t_uchar)(ctrl->scene->canv.width >> 8);
	dib_h[6] = (t_uchar)(ctrl->scene->canv.width >> 16);
	dib_h[7] = (t_uchar)(ctrl->scene->canv.width >> 24);
	dib_h[8] = (t_uchar)-ctrl->scene->canv.height;
	dib_h[9] = (t_uchar)(-ctrl->scene->canv.height >> 8);
	dib_h[10] = (t_uchar)(-ctrl->scene->canv.height >> 16);
	dib_h[11] = (t_uchar)(-ctrl->scene->canv.height >> 24);
	dib_h[12] = 1;
	dib_h[14] = 32;
	write(fd, dib_h, 40);
}

static void		ft_wrtie_img_data(t_ctrl *c, int fd)
{
	t_canvas	canv;
	int			i;

	canv = c->scene->canv;
	i = 0;
	while (i < (c->img.size_line / 4) * canv.height)
	{
		if ((i % (c->img.size_line / 4)) < canv.width)
			write(fd, &c->img.data[i * 4], 4);
		i++;
	}
}

t_bool			ft_write_bmp(t_ctrl *ctrl, int fd)
{
	static t_bool		bool_visited = false;

	if (bool_visited == false)
	{
		ft_write_bmp_header(ctrl, fd);
		ft_write_dib_header(ctrl, fd);
	}
	ft_wrtie_img_data(ctrl, fd);
	bool_visited = true;
	return (success);
}
