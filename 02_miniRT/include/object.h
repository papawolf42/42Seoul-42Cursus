/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 02:40:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/26 02:51:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ray.h"

typedef struct s_sphere		t_sphere;

struct s_sphere
{
	t_point3		center;
	double			radius;
};

#endif
