/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:26:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 01:17:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "alias.h"
#include "parse.h"
#include "utils.h"

double		ft_atof(char *s)
{
	int			sign;
	char		**splits;
	double		integer;
	double		fraction;

	sign = 1;
	splits = ft_split(s, '.');
	integer = (double)ft_atoi_plus(splits[0]);
	if (splits[0][0] == '-')
		sign = -1;
	fraction = 0;
	if (splits[1] != NUL)
	{
		fraction = (double)ft_atoi_plus(splits[1]);
		fraction /= pow(10, ft_strlen(splits[1]));
	}
	ft_destroy_splits(splits);
	return (sign * (integer + fraction));
}
