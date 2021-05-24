/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:19:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 00:02:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "event.h"
#include "object.h"
#include "utils.h"

int					ft_up_radius(t_ctrl *c)
{
	void			*object;
	t_object_type	type;

	if (c->mode == 'c' || c->mode == 'l')
	{
		object = c->object_selected->object;
		type = c->object_selected->type;
		if (type == sp)
			((t_sphere *)object)->radius += c->unit_resize;
		if (type == cy)
			((t_cylinder *)object)->radius += c->unit_resize;
	}
	return (true);
}

int					ft_down_radius(t_ctrl *c)
{
	void			*object;
	t_object_type	type;

	if (c->mode == 'c' || c->mode == 'l')
	{
		object = c->object_selected->object;
		type = c->object_selected->type;
		if (type == sp && ((t_sphere *)object)->radius > c->unit_resize)
			((t_sphere *)object)->radius -= c->unit_resize;
		if (type == cy && ((t_cylinder *)object)->radius > c->unit_resize)
			((t_cylinder *)object)->radius -= c->unit_resize;
	}
	return (true);
}

int					ft_up_length_ratio(t_ctrl *c)
{
	void			*object;
	t_object_type	type;

	if (c->mode == 'c' || c->mode == 'l')
	{
		object = c->object_selected->object;
		type = c->object_selected->type;
		if (type == sq)
			((t_square *)object)->side_len += c->unit_resize;
		if (type == cy)
			((t_cylinder *)object)->height += c->unit_resize;
	}
	if (c->mode == 'L')
	{
		object = ft_return_object(c->scene->light_list, c->scene->idx_l);
		((t_light *)object)->ratio += 0.1;
		((t_light *)object)->ratio = ft_min(((t_light *)object)->ratio, 1.0);
	}
	return (true);
}

int					ft_down_length_ratio(t_ctrl *c)
{
	void			*object;
	t_object_type	type;

	if (c->mode == 'c' || c->mode == 'l')
	{
		object = c->object_selected->object;
		type = c->object_selected->type;
		if (type == sq && ((t_square *)object)->side_len > c->unit_resize)
			((t_square *)object)->side_len -= c->unit_resize;
		if (type == cy && ((t_cylinder *)object)->height > c->unit_resize)
			((t_cylinder *)object)->height -= c->unit_resize;
	}
	if (c->mode == 'L')
	{
		object = ft_return_object(c->scene->light_list, c->scene->idx_l);
		((t_light *)object)->ratio -= 0.1;
		((t_light *)object)->ratio = ft_max(((t_light *)object)->ratio, 0.0);
	}
	return (true);
}
