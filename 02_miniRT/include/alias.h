/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:51:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 11:36:36 by gunkim           ###   ########.fr       */
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

# define MOUSE_PRESSED 4

# define MAX(A, B) (((A) < (B)) && ((A) = (B))) || (((A) > (B)) && ((B) = (A)))
# define MIN(A, B) (((A) > (B)) && ((A) = (B))) || (((A) < (B)) && ((B) = (A)))

# define GNL_SUCCESS 1
# define GNL_EOF 0
# define GNL_FAIL -1

# define EMPTY_LINE 1

# define WHITE_SPACE "\t\n\v\f\r "

typedef enum
{
	false = 0,
	true = 1
}		t_bool;

typedef enum
{
	front = 1,
	back = -1
}		t_front;

#endif
