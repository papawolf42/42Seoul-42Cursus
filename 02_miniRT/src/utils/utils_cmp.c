/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:47:52 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 01:17:23 by gunkim           ###   ########.fr       */
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
