/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:22:44 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 22:00:30 by gunkim           ###   ########.fr       */
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
