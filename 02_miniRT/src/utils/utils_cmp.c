/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:47:52 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/02 00:33:51 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double		ft_min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double		ft_saturate(double a)
{
	if (a > 1)
		return (1);
	else if (a < 0)
		return (0);
	return (a);
}