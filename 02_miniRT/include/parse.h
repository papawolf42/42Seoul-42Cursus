/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:13:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 00:35:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

# define OPEN_FAIL -1

# define GNL_SUCCESS 1
# define GNL_EOF 0
# define GNL_FAIL -1

# define STR_SAME 0

# define WHITE_SPACE "\t\n\v\f\r "
# define COMMA ","

t_bool			ft_pass_line(t_scene *s, char **splits);
t_bool			ft_destroy_splits(char **splits);
t_bool			ft_parse_rt(t_ctrl *ctrl, char *rt_file);
t_bool			ft_parse_line(t_scene *scene, char *line);

t_bool			ft_parse_resolution(t_scene *s, char **splits);
t_bool			ft_parse_ambient(t_scene *s, char **splits);
t_bool			ft_parse_camera(t_scene *s, char **splits);
t_bool			ft_parse_light(t_scene *s, char **splits);
t_bool			ft_parse_sphere(t_scene *s, char **splits);
t_bool			ft_parse_plane(t_scene *s, char **splits);
t_bool			ft_parse_square(t_scene *s, char **splits);
void			ft_square_set(t_square *square);
t_bool			ft_parse_cylinder(t_scene *s, char **splits);
void			ft_cylinder_set(t_cylinder *cyl);
t_bool			ft_parse_triangle(t_scene *s, char **splits);
void			ft_triangle_set(t_triangle *triangle);


t_bool			ft_parse_vector(t_vec3 *dst, char *src);
t_bool			ft_parse_normal(t_vec3 *dst, char *src);
t_bool			ft_parse_color(t_color *dst, char *src);

t_bool			ft_parse_integer(int *dst, char *src);
t_bool			ft_parse_real(double *dst, char *src);
t_bool			ft_parse_color_integer(double *dst, char *src);

t_bool			ft_range_integer(int *value, int min, int max);
t_bool			ft_range_real(double *value, double min, double max);

#endif