/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:36:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 01:00:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_nonformat(t_fmt *fmt)
{
	while (*fmt->str != '%' && *fmt->str != '\0')
	{
		fmt->rtn += write(1, fmt->str, 1);
		fmt->str++;
	}
	return (0);
}

int		ft_parse_format(t_fmt *fmt)
{
	if (*fmt->str == '\0')
		return (0);
	fmt->str++;
	if (ft_parse_flag(fmt) == ERROR)
		return (ERROR);
	if (ft_parse_prec(fmt) == ERROR)
		return (ERROR);
	if (ft_parse_len(fmt) == ERROR)
		return (ERROR);
	if (ft_parse_spec(fmt) == ERROR)
		return (ERROR);
	return (0);
}

int		ft_print_format(t_fmt *fmt)
{
	if (fmt->spec == 'd' || fmt->spec == 'i' || fmt->spec == 'u' ||
			fmt->spec == 'o' || fmt->spec == 'x' || fmt->spec == 'X')
	{
		if (ft_print_integer(fmt) == ERROR)
			return (ERROR);
	}
	else if (fmt->spec == 'c' || fmt->spec == 's')
	{
		if (ft_print_letter(fmt) == ERROR)
			return (ERROR);
	}
	else if (fmt->spec == 'f' || fmt->spec == 'e' || fmt->spec == 'g')
	{
		if (ft_print_floating(fmt) == ERROR)
			return (ERROR);
	}
	else if (fmt->spec == 'p' || fmt->spec == 'n' || fmt->spec == '%')
	{
		if (ft_print_etc(fmt) == ERROR)
			return (ERROR);
	}
	return (0);
}
