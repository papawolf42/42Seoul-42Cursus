/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:51:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/02 04:12:53 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

# include <float.h>

# define M_EPSILON 1e-8
# define M_INFINITY 1.797683e308
# define M_PI2 6.283185307179586231995926937088
# define NUL (void *)0

# define MOUSE_PRESSED 4

# define MAX(A, B) (((A) < (B)) && ((A) = (B))) || (((A) > (B)) && ((B) = (A)))
# define MIN(A, B) (((A) > (B)) && ((A) = (B))) || (((A) < (B)) && ((B) = (A)))

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