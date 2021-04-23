/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:35:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/23 18:17:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color;

struct						s_vec3
{
	double		x;
	double		y;
	double		z;
};

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
