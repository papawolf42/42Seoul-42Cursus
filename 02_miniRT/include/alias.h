/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:51:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 19:27:17 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

# include <float.h>
# include <math.h>

# define M_EPSILON 1e-8
# define M_INFINITY 1.797683e308
# define M_PI2 6.283185307179586231995926937088
# define NUL (void *)0
# define INDEX_FISH_EYE 0.70710678118
# define DEGREE_TO_RADIAN (M_PI / 180)
# define SAMPLING 2

# define UNIT_MOVE 10
# define UNIT_ROTATE_DEGREE 45
# define UNIT_ROTATE (UNIT_ROTATE_DEGREE * DEGREE_TO_RADIAN)
# define AXIS_UP V_SET(0, 1, 0)

# define NUM_THREAD 8

typedef enum
{
	false = 0,
	true = 1,
	success = 0,
	fail = 1
}		t_bool;

typedef enum
{
	front = 1,
	back = -1
}		t_front;

#endif
