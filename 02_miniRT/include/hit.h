/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:59:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 16:24:07 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

#include "struct.h"

t_ray		ft_ray_init(t_ctrl *c, t_camera *cam, double x, double y);
t_ray		ft_ray_init_aa(t_ctrl *c, t_camera *cam, double x, double y);
t_color		ft_ray_to_color(t_ray ray, t_ctrl *c);
t_vec3		ft_ray_at(t_ray *ray, double t);
t_front		ft_ray_determine_front(t_ray *ray, t_hit_rec *rec);

t_bool		ft_hit(t_object_list *obj, t_ray *ray, t_hit_rec *rec);
t_bool		ft_hit_object(t_object_list *obj, t_ray *ray,t_hit_rec *rec);
t_bool		ft_hit_sphere(t_sphere *sp, t_ray *ray, t_hit_rec *rec);
t_bool		ft_hit_plane(t_plane *pl, t_ray *ray, t_hit_rec *rec);
t_bool		ft_hit_square(t_square *sq, t_ray *ray, t_hit_rec *rec);
t_bool		ft_hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_rec *rec);
t_bool		ft_hit_triangle(t_triangle *tr, t_ray *ray, t_hit_rec *rec);

t_color		ft_phong_color(t_scene *s, t_ray *ray, t_hit_rec *rec);

#endif
