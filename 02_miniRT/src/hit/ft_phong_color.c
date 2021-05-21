/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:54:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 00:57:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "utils.h"
#include "hit.h"

static t_color		ft_phong_color_compute(t_light *light, t_ray *ray, t_hit_rec *rec, t_ambient a)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		light_intensity;

	t_vec3		to_light;
	t_vec3		to_view;
	t_vec3		reflect;

	double		kd;
	double		ks;
	double		ksn;

	double		attenuation_radius;
	double		attenuation_distance;
	double		radius_attenuation;
	double		distance;

	radius_attenuation = 4;
	distance = V_LEN(V_MINUS(light->p, rec->p)) / 3;
	if (radius_attenuation < distance)
		return (V_COLOR(0, 0, 0));

	to_light = V_UNIT(V_MINUS(light->p, rec->p));
	to_view = V_UNIT(V_MINUS(ray->org, rec->p));
	reflect = V_UNIT(V_REFLECT(V_SCALAR(to_light, -1), rec->normal));

	kd = ft_max(V_DOT(V_UNIT(rec->normal), to_light), 0.0);
	ks = 0.3;
	ksn = 32;
	ambient = V_SCALAR(a.color, a.ratio);
	diffuse = V_SCALAR(light->color, kd);
	specular = V_SCALAR(light->color, ks * pow(ft_max(V_DOT(reflect, to_view), 0.0), ksn));
	// attenuation_radius = pow(ft_saturate(1 - pow(distance / radius_attenuation, 4)), 2);
	attenuation_radius = 1;
	// attenuation_distance = 1 / (pow(distance, 2) + 1);
	attenuation_distance = 1;
	light_intensity = V_SCALAR(V_PLUS(diffuse, specular), light->ratio);
	// return (V_PLUS(ambient, V_SCALAR(light_intensity, attenuation_distance * attenuation_radius)));
	return (V_PLUS(ambient, V_MULT(light->color, light_intensity)));
}

static t_bool		ft_is_not_shadow(t_object_list *obj, t_light *light, t_hit_rec *rec)
{
	t_ray		back_track_ray;
	t_hit_rec	rec_light;

	back_track_ray.org = rec->p;
	back_track_ray.dir = V_MINUS(light->p, rec->p);

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

	// ray->org = ray->org;
	lights = s->light_list;
	light_stack = V_COLOR(0, 0, 0);
	// light_stack = V_COLOR(1, 1, 1);
	while (lights)
	{
		if (ft_is_not_shadow(s->object_list, lights->object, rec))
			light_stack = V_PLUS(light_stack, ft_phong_color_compute(lights->object, ray, rec, s->ambient));
		lights = lights->next;
	}
	return (V_MIN(V_MULT(light_stack, rec->color), V_SET(0.999, 0.999, 0.999)));
}