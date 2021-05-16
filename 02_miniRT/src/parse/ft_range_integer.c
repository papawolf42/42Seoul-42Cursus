/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:33:29 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 21:55:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"

t_bool		ft_range_integer(int *value, int min, int max)
{
	if (min <= *value && *value <= max)
		return (success);
	return (fail);
}
