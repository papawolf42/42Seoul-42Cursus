/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/22 01:14:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "struct.h"

/*
** main.c
*/
void		ft_render(t_ctrl *ctrl);
void		ft_minirt(t_ctrl *ctrl);
int			main(int argc, char *argv[]);

/*
** parse.c
*/
void		ft_read_rt(t_ctrl *ctrl, char *rt_file);

/*
** utils_str.c
*/
int			ft_is_endstr(char *big, char *little);

/*
** utils_color.c
*/
int			ft_get_rgb_int(t_color *color);

#endif