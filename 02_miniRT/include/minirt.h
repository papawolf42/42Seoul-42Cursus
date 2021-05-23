/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 15:23:49 by gunkim           ###   ########.fr       */
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

int			main(int argc, char *argv[]);

t_bool		ft_minirt(t_ctrl *ctrl);

t_bool		ft_switch_multi_thread(t_ctrl *ctrl);
t_bool		ft_render(t_ctrl *ctrl);
t_bool		ft_render_multi_thread(t_ctrl *ctrl);

t_color		ft_ray_to_color(t_ray ray, t_ctrl *c);

#endif
