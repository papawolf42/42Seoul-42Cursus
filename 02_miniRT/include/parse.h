/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:13:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 15:18:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

t_bool			ft_pass_line(t_scene *s, char **splits);
t_bool			ft_destroy_splits(char **splits);
t_bool			ft_break_parse(t_scene *s, char **splits);
t_bool			ft_parse_rt(t_ctrl *ctrl, char *rt_file);
t_bool			ft_parse_line(t_scene *scene, char *line);

t_bool			ft_parse_resolution(t_scene *s, char **splits);
t_bool			ft_parse_ambient(t_scene *s, char **splits);
t_bool			ft_parse_camera(t_scene *s, char **splits);
t_bool			ft_parse_light(t_scene *s, char **splits);
t_bool			ft_parse_sphere(t_scene *s, char **splits);
t_bool			ft_parse_plane(t_scene *s, char **splits);

t_bool			ft_parse_vector(t_vec3 *dst, char *src);
t_bool			ft_parse_normal(t_vec3 *dst, char *src);
t_bool			ft_parse_color(t_color *dst, char *src);

t_bool			ft_parse_color_integer(double *dst, char *src);
t_bool			ft_range_integer(int *value, int min, int max);
t_bool			ft_range_real(double *value, double min, double max);

#endif