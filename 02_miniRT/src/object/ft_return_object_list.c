/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_object_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:21:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 00:14:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void			*ft_return_object(t_object_list *list, int idx)
{
	while (idx-- && list->next)
		list = list->next;
	return (list->object);
}
