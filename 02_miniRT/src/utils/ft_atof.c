/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:26:47 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 18:07:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "alias.h"
#include "parse.h"

double		ft_atof(char *s)
{
	char		**splits;
	double		integer;
	double		fraction;

	splits = ft_split(s, '.');
	integer = (double)ft_atoi(splits[0]);
	fraction = 0;
	if (splits[1] != NUL)
		fraction = (double)ft_atoi(splits[1]);
	fraction /= pow(10, ft_strlen(splits[1])); // 0은 10으로 나눔. 1은 10으로 나눔, 9는 10으로 10은 100으로 나눔. 11은 100으로 나눔. 
	ft_destroy_splits(splits);
	return (integer + fraction);
}