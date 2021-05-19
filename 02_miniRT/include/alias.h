/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:51:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 22:30:18 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

# include <float.h>

# define M_EPSILON 1e-8
# define M_INFINITY 1.797683e308
# define M_PI2 6.283185307179586231995926937088
# define NUL (void *)0
# define FISH_EYE_INDEX 0.70710678118

# define UNIT_MOVE 1
# define UNIT_ROTATE 15
# define AXIS_UP V_SET(0, 1, 0)

# define MAX(A, B) (((A) < (B)) && ((A) = (B))) || (((A) > (B)) && ((B) = (A)))
# define MIN(A, B) (((A) > (B)) && ((A) = (B))) || (((A) < (B)) && ((B) = (A)))

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
