/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/20 22:04:19 by gunkim           ###   ########.fr       */
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

t_ray		ft_ray_init(t_canvas *canv, t_camera *cam, int x, int y);
t_bool		ft_hit(t_object_list *obj, t_ray *ray, t_hit_rec *rec);


#endif
