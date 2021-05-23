/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:22:44 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 19:11:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vector.h"
# include "ray.h"

typedef struct s_vec3		t_color;

int				ft_rgb_to_data(t_color color);
t_color			ft_color_average(t_color *data, int x, int y, int width);

#endif
