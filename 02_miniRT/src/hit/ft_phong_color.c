/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:54:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 21:10:10 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "utils.h"
#include "hit.h"
#include "phong.h"

static t_color		ft_phong_color_compute(t_light *light,
												t_ray *ray, t_hit_rec *rec)
{
	t_var_phong		v;

	v.to_light = ft_vunit(ft_vminus(light->p, rec->p));
	v.to_view = ft_vunit(ft_vminus(ray->org, rec->p));
	v.reflect = ft_vunit(ft_vreflect(ft_vscalar(v.to_light, -1), rec->normal));
	v.kd = ft_max(ft_vdot(ft_vunit(rec->normal), v.to_light), 0.0);
	v.diffuse = ft_vscalar(light->color, v.kd);
	v.specular = ft_vscalar(light->color,
					KS * pow(ft_max(ft_vdot(v.reflect, v.to_view), 0.0), KSN));
	v.light_intensity = ft_vscalar(ft_vplus(v.diffuse, v.specular),
																light->ratio);
	return (ft_vmult(light->color, v.light_intensity));
}

static t_bool		ft_is_not_shadow(t_object_list *obj, t_light *light,
																t_hit_rec *rec)
{
	t_ray		back_track_ray;
	t_hit_rec	rec_light;

	back_track_ray.org = rec->p;
	back_track_ray.dir = ft_vminus(light->p, rec->p);
	rec_light.t_min = M_EPSILON;
	rec_light.t_max = 1;
	while (obj)
	{
		if (ft_hit_object(obj, &back_track_ray, &rec_light))
		{
			return (false);
		}
		obj = obj->next;
	}
	return (true);
}

t_color				ft_phong_color(t_scene *s, t_ray *ray, t_hit_rec *rec)
{
	t_color			light_stack;
	t_object_list	*lights;

	lights = s->light_list;
	light_stack = ft_vset(0, 0, 0);
	while (lights)
	{
		if (ft_is_not_shadow(s->object_list, lights->object, rec))
			light_stack = ft_vplus(light_stack,
							ft_phong_color_compute(lights->object, ray, rec));
		lights = lights->next;
	}
	light_stack = ft_vplus(light_stack, s->ambient.color);
	return (ft_vmin(ft_vmult(light_stack, rec->color),
												ft_vset(1.0, 1.0, 1.0)));
}
