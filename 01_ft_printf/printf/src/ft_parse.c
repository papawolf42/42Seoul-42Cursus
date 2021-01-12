/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:55:52 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/12 18:24:25 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
int			ft_parse_nbr_onestar(t_fmt *fmt, t_flg flg)
{
}

int			ft_parse_nbr_nonestar(t_flg *fmt, t_flg flg)
{
}
*/

int			ft_atoi_parse_star(t_fmt *fmt)
{
	ullint		result;
	int			sign;

	result = 0;
	sign = 1;
	while ((9 <= *fmt->str && *fmt->str <= 13) || *fmt->str == ' ')
		fmt->str++;
	if (*fmt->str == '+' || *fmt->str == '-')
		if (*(fmt->str++) == '-')
			sign = -1;
	while ('0' <= *fmt->str && *fmt->str <= '9')
		result = result * 10 + *(fmt->str++) - '0';
	return (sign * result);
}

int			ft_parse_nbr(t_fmt *fmt, t_flg flg)
{
	int		temp;

	if (fmt->flag[star] >= 1)
	{
		if ((temp = va_arg(fmt->ap, int)) < 0 && fmt->wid == 0)
		{
			fmt->flag[dot] = 0;
			fmt->flag[minus] = 1;
			fmt->wid = -1 * temp;
		}
		else if (flg == !dot)
			fmt->wid = temp;
		else if (flg == dot)
			fmt->prec = temp;
		fmt->flag[star] = 0;
		return (0);
	}
	temp = ft_atoi_parse_star(fmt);
	if (temp < 0)
	{
		fmt->wid = -1 * temp;
		fmt->flag[dot] = 0;
		fmt->flag[minus] += 1;
	}
	else if (flg == !dot)
		fmt->wid = temp;
	else if (flg == dot)
		fmt->prec = temp;
	return (0);
}

int			ft_parse_flag(t_fmt *fmt)
{
	while (ft_strchr("-+ #0*", *fmt->str) && *fmt->str)
	{
		if (*fmt->str == '-')
			fmt->flag[minus]++;
		else if (*fmt->str == '+')
			fmt->flag[plus]++;
		else if (*fmt->str == ' ')
			fmt->flag[space]++;
		else if (*fmt->str == '#')
			fmt->flag[hash]++;
		else if (*fmt->str == '0')
			fmt->flag[zero]++;
		else if (*fmt->str == '*')
			fmt->flag[star]++;
		fmt->str++;
	}
	if (ft_parse_nbr(fmt, !dot) == ERROR)
		return (ERROR);
	return (0);
}

int			ft_parse_prec(t_fmt *fmt)
{
	while (ft_strchr(".*", *fmt->str) && *fmt->str)
	{
		if (*fmt->str == '.')
			fmt->flag[dot]++;
		else if (*fmt->str == '*')
			fmt->flag[star]++;
		fmt->str++;
	}
	if (ft_parse_nbr(fmt, dot) == ERROR)
		return (ERROR);
	return (0);
}

/*
int			ft_parse_len(t_fmt *fmt)
{
	return (0);
}
*/

int			ft_parse_spec(t_fmt *fmt)
{
	fmt->spec = *ft_strchr("diuoxXfegcspn%", *fmt->str);
	if (fmt->spec == 0)
		return (ERROR);
	fmt->str++;
	return (0);
}
