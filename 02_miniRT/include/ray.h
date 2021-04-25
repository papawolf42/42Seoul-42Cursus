/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:32:05 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/25 02:57:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <vector.h>

typedef struct s_ray		t_ray;

struct s_ray
{
	t_vec3		dir;
	t_point3	org;
};

#endif