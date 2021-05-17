/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_real.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:33:29 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 12:19:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"

t_bool		ft_range_real(double *value, double min, double max)
{
	if (min <= *value && *value <= max)
		return (success);
	return (fail);
}
