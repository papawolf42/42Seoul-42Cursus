/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:35:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:50:34 by gunkim           ###   ########.fr       */
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

t_vec3						ft_vset(double x, double y, double z);
t_vec3						ft_vmax(t_vec3 one, t_vec3 two);
t_vec3						ft_vmin(t_vec3 one, t_vec3 two);

double						ft_vlen2(t_vec3 vec);
double						ft_vlen(t_vec3 vec);

t_vec3						ft_vplus(t_vec3 one, t_vec3 two);
t_vec3						ft_vminus(t_vec3 one, t_vec3 two);

t_vec3						ft_vscalar(t_vec3 vec, double t);
t_vec3						ft_vmult(t_vec3 one, t_vec3 two);
double						ft_vdot(t_vec3 one, t_vec3 two);
t_vec3						ft_vcross(t_vec3 one, t_vec3 two);
t_vec3						ft_vunit(t_vec3 vec);

t_vec3						ft_vreflect(t_vec3 come, t_vec3 norm);

#endif
