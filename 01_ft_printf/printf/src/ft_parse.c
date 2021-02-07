/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:55:52 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 01:51:47 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parse_flag(t_fmt *fmt)
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

int				ft_parse_prec(t_fmt *fmt)
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

int				ft_parse_len(t_fmt *fmt)
{
	while (ft_strchr("lh", *fmt->str) && *fmt->str)
	{
		if (*fmt->str == 'l' && *(fmt->str + 1) != 'l')
		{
			fmt->len = 'l';
			fmt->str += 1;
		}
		else if (*fmt->str == 'l' && *(fmt->str + 1) == 'l')
		{
			fmt->len = 'L';
			fmt->str += 2;
		}
		else if (*fmt->str == 'h' && *(fmt->str + 1) != 'h')
		{
			fmt->len = 'h';
			fmt->str += 1;
		}
		else if (*fmt->str == 'h' && *(fmt->str + 1) == 'h')
		{
			fmt->len = 'H';
			fmt->str += 2;
		}
	}
	return (0);
}

static char		ft_strchr_notpnt(const char *s, int c)
{
	size_t		len;

	len = 14;
	while (len--)
	{
		if (*s == c)
			return (c);
		s++;
	}
	return (0);
}

int				ft_parse_spec(t_fmt *fmt)
{
	fmt->spec = ft_strchr_notpnt("diuoxXfegcspn%", *fmt->str);
	if (fmt->spec == 0)
		return (ERROR);
	fmt->str++;
	return (0);
}
