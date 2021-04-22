/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "struct.h"

typedef enum
{
	err_divided_zero
}		t_err;


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

/*
** utils_vec.c
*/
void		ft_vec_set(t_vec3 *vec3, double x, double y, double z);
double		ft_vec_len2(t_vec3 *vec);
double		ft_vec_len(t_vec3 *vec);

/*
** utils_vec2.c
*/
void		ft_vec_add(t_vec3 *one, t_vec3 *two);
void		ft_vec_add2(t_vec3 *one, t_vec3 *two);
void		ft_vec_sub(t_vec3 *one, t_vec3 *two);
void		ft_vec_sub2(t_vec3 *one, t_vec3 *two);

/*
** utils_vec3.c
*/
void		ft_vec_scalar(t_vec3 *vec, double t);
double		ft_vec_dot(t_vec3 *one, t_vec3 *two);
void		ft_vec_cross(t_vec3 *new, t_vec3 *one, t_vec3 *two);
void		ft_vec_unit(t_vec3 *vec);

#endif