/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:13:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 16:24:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

t_bool		ft_break_parse(t_scene *s, char **splits);
t_bool		ft_parse_rt(t_ctrl *ctrl, char *rt_file);
t_bool		ft_parse_line(t_scene *scene, char *line);

#endif