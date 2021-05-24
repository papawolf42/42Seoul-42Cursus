/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:19:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 22:48:50 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "event.h"

int					ft_increase_radius(t_ctrl *ctrl)
{
	void			*object;
	t_object_type	type;

	object = ctrl->object_selected->object;
	type = ctrl->object_selected->type;
	if (type == sp)
		((t_sphere *)object)->radius += ctrl->unit_resize;
	if (type == cy)
		((t_cylinder *)object)->radius += ctrl->unit_resize;
	return (true);
}

int					ft_decrease_radius(t_ctrl *ctrl)
{
	void			*object;
	t_object_type	type;

	object = ctrl->object_selected->object;
	type = ctrl->object_selected->type;
	if (type == sp && ((t_sphere *)object)->radius > ctrl->unit_resize)
		((t_sphere *)object)->radius -= ctrl->unit_resize;
	if (type == cy && ((t_cylinder *)object)->radius > ctrl->unit_resize)
		((t_cylinder *)object)->radius -= ctrl->unit_resize;
	return (true);
}

int					ft_increase_length(t_ctrl *ctrl)
{
	void			*object;
	t_object_type	type;

	object = ctrl->object_selected->object;
	type = ctrl->object_selected->type;
	if (type == sq)
		((t_square *)object)->side_len += ctrl->unit_resize;
	if (type == cy)
		((t_cylinder *)object)->height += ctrl->unit_resize;
	return (true);
}

int					ft_decrease_length(t_ctrl *ctrl)
{
	void			*object;
	t_object_type	type;

	object = ctrl->object_selected->object;
	type = ctrl->object_selected->type;
	if (type == sq && ((t_square *)object)->side_len > ctrl->unit_resize)
		((t_square *)object)->side_len -= ctrl->unit_resize;
	if (type == cy && ((t_cylinder *)object)->height > ctrl->unit_resize)
		((t_cylinder *)object)->height -= ctrl->unit_resize;
	return (true);
}
