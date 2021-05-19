/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:20:15 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 21:25:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_mat44			t_mat44;

struct				s_mat44
{
	t_vec3			x;
	t_vec3			y;
	t_vec3			z;
	t_vec3			trans;
	double			scale;
};

t_mat44				ft_mat_set(t_vec3 x, t_vec3 y, t_vec3 z, t_vec3 trans);
t_mat44				ft_matrix_identity(void);
t_vec3				ft_linear_transform(t_mat44 mat, t_vec3 vec);


#endif
