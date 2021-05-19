/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:23:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 15:51:04 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "alias.h"
# include "struct.h"

t_bool			ft_init_object_list(t_scene *s);
t_bool			ft_addback_object_list(t_object_type type, void *object, t_scene *s);
void			*ft_return_object(t_object_list *list, int idx);

#endif
