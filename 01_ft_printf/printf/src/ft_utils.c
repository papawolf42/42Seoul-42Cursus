/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:44:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/10 22:22:37 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_count_digit(int nbr)
{
	int		base;
	int		sign;
	int		digit;
	
	base = 1;
	sign = 0;
	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		sign++;
	}
	while (nbr >= base)
	{
		base *= 10;
		digit++;
	}
	return (sign + digit);
}

int			abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}
