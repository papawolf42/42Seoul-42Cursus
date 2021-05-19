/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 16:23:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "struct.h"
# include "color.h"

typedef enum
{
	err_divided_zero
}		t_err;

/*
** main.c
*/
t_bool		ft_render(t_ctrl *ctrl);
void		ft_minirt(t_ctrl *ctrl);
int			main(int argc, char *argv[]);

/*
** utils_cmp.c
*/
double		ft_max(double a, double b);
double		ft_min(double a, double b);
double		ft_saturate(double a);

/*
** utils_str.c
*/
int			ft_is_endstr(char *big, char *little);

#endif
