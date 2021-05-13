/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:20:15 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/12 20:53:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"
// # include "struct.h"

typedef struct s_mat44			t_mat44;

struct				s_mat44
{
	t_vec3			x;
	t_vec3			y;
	t_vec3			z;
	t_vec3			trans;
	double			scale;
};

#endif
