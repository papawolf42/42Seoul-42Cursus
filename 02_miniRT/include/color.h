/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:22:44 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/25 20:51:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vector.h"
# include "ray.h"

typedef struct s_vec3		t_color;

/*
** utils_color.c
*/
int			ft_rgb_to_data(t_color color);
int			ft_pixel_color(t_ray *ray);

#endif
