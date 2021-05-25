/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:51:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 14:05:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

# include <float.h>
# include <math.h>

# define M_EPSILON				1e-8
# define M_INFINITY				1.797683e308
# define M_PI2					6.283185307179586231995926937088
# define INDEX_FISH_EYE			0.70710678118

# define SAMPLING				2
# define NUM_THREAD				12

typedef unsigned char			t_uchar;

typedef enum
{
	false = 0,
	true = 1,
	success = 0,
	fail = 1
}	t_bool;

typedef enum
{
	front = 1,
	back = -1
}	t_front;

#endif
