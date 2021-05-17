/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 15:16:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "struct.h"
#include "vector.h"
#include "alias.h"
#include "error.h"
#include "utils.h"
#include "parse.h"

t_bool		ft_parse_line(t_scene *scene, char *line)
{
	char				**splits;
	int					i;
	static t_pft_parse	pft_parse[] = {
		{"", ft_pass_line}, {"#", ft_pass_line},
		{"R", ft_parse_resolution},
		{"A", ft_parse_ambient},
		{"c", ft_parse_camera},
		{"l", ft_parse_light},
		{"sp", ft_parse_sphere},
		{"pl", ft_parse_plane},
		// {"sq", ft_parse_square},
		// {"cy", ft_parse_cylinder},
		// {"tr", ft_parse_triangle},
		{NUL, NUL}
	};

	i = 0;
	splits = ft_split_rt(line, WHITE_SPACE);
	while (pft_parse[i].id && *splits && ft_strncmp(pft_parse[i].id, splits[0], 4))
		i++;
	if (pft_parse[i].id == NUL)
		return (ft_err_msg(ERR_PAR_NOID) && ft_destroy_splits(splits));// 여기서 이제껏 malloc했던 scene들을 모두 free해주어야함.
	if (pft_parse[i].parse(scene, splits))
		return (ft_destroy_splits(splits));
	ft_destroy_splits(splits);
	return (success);
}

t_bool		ft_parse_rt(t_ctrl *ctrl, char *rt_file)
{
	int		fd;
	int		ret;
	char	*line;

	ctrl->scene = (t_scene *)malloc(sizeof(t_scene));
	ft_object_list_init(ctrl->scene);
	fd = open(rt_file, O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == GNL_FAIL)
			return (ft_err_msg(ERR_GNL));
		if (ret == GNL_EOF)
			break;
		if (ft_parse_line(ctrl->scene, line))
			return (fail);
		free(line);
	}
	free(line);
	return (0);
}
