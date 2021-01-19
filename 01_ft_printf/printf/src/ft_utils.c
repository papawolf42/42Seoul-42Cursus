/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:44:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/19 20:54:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_count_digit(t_llint nbr)
{
	int			digit;
	t_ullint	multi;
	int			sign;

	digit = 0;
	multi = 1;
	sign = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		sign++;
	}
	while ((t_ullint)nbr >= multi)
	{
		multi *= 10;
		digit++;
	}
	return (sign + digit);
}

int			ft_count_digit_u(t_ullint nbr, char cbase)
{
	int			digit;
	t_ullint	multi;
	t_uint		base;

	digit = 0;
	multi = 1;
	if (cbase == 'u')
		base = 10;
	else if (cbase == 'o')
		base = 8;
	else if (cbase == 'x' || cbase == 'X')
		base = 16;
	if (nbr == 0)
		return (1);
	if (nbr >= base)
	{
		nbr /= base;
		digit++;
	}
	while (nbr >= multi)
	{
		multi *= base;
		digit++;
	}
	return (digit);
}

int			ft_abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
