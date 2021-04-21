/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:54:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/21 23:33:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec3		t_vec3;
typedef struct s_matrix		t_matrix;
typedef struct s_image		t_image;
typedef struct s_scene		t_scene;
typedef struct s_ctrl		t_ctrl;

struct				s_vec3
{
	double		x;
	double		y;
	double		z;
};

struct				s_matrix
{
	t_vec3		vx;
	t_vec3		vy;
	t_vec3		vz;
};

struct				s_image
{
	void		*img_ptr;
	char		*data;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
};

struct				s_scene
{
	int			width;
	int			height;
};

struct				s_ctrl
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	t_scene		scene;
};

#endif
