/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:35:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/25 20:54:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;

struct						s_vec3
{
	double		x;
	double		y;
	double		z;
};

# define V_SET(X, Y, Z)			ft_vec3_set((X), (Y), (Z))
# define V_LEN(V)				ft_vec3_len((V))
# define V_LEN2(V)				ft_vec3_len2((V))
# define V_PLUS(A, B)			ft_vec3_plus((A), (B))
# define V_MINUS(A, B)			ft_vec3_minus((A), (B))
# define V_SCALAR(V, T)			ft_vec3_scalar((V), (T))
# define V_DOT(A, B)			ft_vec3_dot((A), (B))
# define V_CROSS(A, B)			ft_vec3_cross((A), (B))
# define V_UNIT(V)				ft_vec3_unit((V))

/*
** ft_vec3.c
*/
t_vec3		ft_vec3_set(double x, double y, double z);

/*
** ft_vec3_length.c
*/
double		ft_vec3_len2(t_vec3 vec);
double		ft_vec3_len(t_vec3 vec);

/*
** ft_vec3_plus_minus.c
*/
t_vec3		ft_vec3_plus(t_vec3 one, t_vec3 two);
t_vec3		ft_vec3_minus(t_vec3 one, t_vec3 two);

/*
** ft_vec3_multiplication.c
*/
t_vec3		ft_vec3_scalar(t_vec3 vec, double t);
double		ft_vec3_dot(t_vec3 one, t_vec3 two);
t_vec3		ft_vec3_cross(t_vec3 one, t_vec3 two);
t_vec3		ft_vec3_unit(t_vec3 vec);

#endif
