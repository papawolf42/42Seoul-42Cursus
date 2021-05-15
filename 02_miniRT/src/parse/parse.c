/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 22:21:25 by gunkim           ###   ########.fr       */
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

t_bool		ft_parse_line(t_scene *scene, char *line)
{
	char				**splits;
	int					i;
	static t_pft_parse	pft_parse[] = {
		{"R", ft_parse_resolution},
		// {"A", ft_parse_ambience},
		// {"c", ft_parse_camera},
		// {"l", ft_parse_light},
		// {"sp", ft_parse_sphere},
		// {"pl", ft_parse_plane},
		// {"sq", ft_parse_square},
		// {"cy", ft_parse_cylinder},
		// {"tr", ft_parse_triangle},
		{NUL, NUL}
	};

	i = 0;
	splits = ft_split_rt(line, WHITE_SPACE);
	if (splits == NUL)
		return (EMPTY_LINE);
	while (pft_parse[i].id && ft_strncmp(pft_parse[i].id, splits[0], 4))
		i++;
	if (pft_parse[i].id == NUL)
		return (ft_err_msg(ERR_PAR_NOID));// 여기서 이제껏 malloc했던 scene들을 모두 free해주어야함.
	return (pft_parse[i].parse(scene, splits));
}

t_bool		ft_parse_rt(t_ctrl *ctrl, char *rt_file)
{
	int		fd;
	int		ret;
	char	*line;

	ctrl->scene = (t_scene *)malloc(sizeof(t_scene));
	fd = open(rt_file, O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == GNL_FAIL)
			return (ft_err_msg(ERR_GNL));
		if (ret == GNL_EOF)
			break;
		ft_parse_line(ctrl->scene, line);
		free(line);
	}
	free(line);

	ft_object_list_init(ctrl->scene);
	ft_object_list(cam, ft_camera(V_POINT(0, 0, 0), V_SET(0, 0, 1), 100, 2.0, 1.0, ctrl->scene->canv.aspect_ratio), ctrl->scene->camera_list);

	ft_object_list(sp, ft_sphere(V_POINT(-1, -0.5, 2), 0.5, V_COLOR(0.933, 0.682, 0.639)), ctrl->scene->object_list);
	ft_object_list(sp, ft_sphere(V_POINT(0, -0.5, 2), 0.5, V_COLOR(0.6, 0.714, 0.675)), ctrl->scene->object_list);
	ft_object_list(sp, ft_sphere(V_POINT(1, -0.5, 2), 0.5, V_COLOR(0.616, 0.710, 0.800)), ctrl->scene->object_list);

	ft_object_list(pl, ft_plane(V_POINT(0, -1, 0), V_SET(0, 1, 0), V_COLOR(0.635, 0.639, 0.769)), ctrl->scene->object_list);
	ft_object_list(pl, ft_plane(V_POINT(-1.5, 0, 0), V_SET(1, 0, 0), V_COLOR(0.635, 0.639, 0.769)), ctrl->scene->object_list);
	ft_object_list(pl, ft_plane(V_POINT(1.5, 0, 0), V_SET(-1, 0, 0), V_COLOR(0.635, 0.639, 0.769)), ctrl->scene->object_list);
	ft_object_list(pl, ft_plane(V_POINT(0, 0, 5), V_SET(0, 0, 1), V_COLOR(0.635, 0.639, 0.769)), ctrl->scene->object_list);
	ft_object_list(pl, ft_plane(V_POINT(0, 2, 0), V_SET(0, -1, 0), V_COLOR(0.635, 0.639, 0.769)), ctrl->scene->object_list);
	ft_object_list(l, ft_light(V_SET(0, 1.5, -1), V_COLOR(10, 10, 10)), ctrl->scene->light_list);

	// ft_object_list(l, ft_light(V_POINT(0, 1, -2.8), V_COLOR(0.6, 1, 1)), ctrl->scene->light_list);
	// ft_object_list(l, ft_light(V_POINT(1, 1.5, 0), V_COLOR(12, 12, 12)), ctrl->scene->light_list);
	// ft_object_list(sq, ft_square(V_POINT(0, 0, -5), V_SET(0, 0, 1), 5, V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	// ft_object_list(sq, ft_square(V_POINT(2.5, 0, -2.5), V_SET(1, 0, 0), 5, V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	// ft_object_list(sq, ft_square(V_POINT(-2.5, 0, -2.5), V_SET(1, 0, 0), 5, V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	// ft_object_list(pl, ft_plane(V_POINT(0, 2.5, 0), V_SET(0, -1, 0), V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	// ft_object_list(pl, ft_plane(V_POINT(0, -2, 0), V_SET(0, 1, 0), V_COLOR(0.5, 0.5, 0.8)), ctrl->scene->object_list);
	// ft_object_list(cy, ft_cylinder(V_POINT(0.5,-2,-2.2),V_SET(0,1,0), 1, 1.5, V_COLOR(0.2,0.18,0.3)), ctrl->scene->object_list);
	return (0);
}
