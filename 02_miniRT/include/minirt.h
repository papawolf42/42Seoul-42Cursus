/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/23 21:15:57 by gunkim           ###   ########.fr       */
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
void		ft_render(t_ctrl *ctrl);
void		ft_minirt(t_ctrl *ctrl);
int			main(int argc, char *argv[]);

/*
** parse.c
*/
void		ft_read_rt(t_ctrl *ctrl, char *rt_file);

/*
** utils_str.c
*/
int			ft_is_endstr(char *big, char *little);

#endif
