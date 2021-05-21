/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:32:05 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/21 21:57:11 by gunkim           ###   ########.fr       */
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