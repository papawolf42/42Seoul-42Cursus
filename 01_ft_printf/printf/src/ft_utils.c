/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:44:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/22 04:00:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
