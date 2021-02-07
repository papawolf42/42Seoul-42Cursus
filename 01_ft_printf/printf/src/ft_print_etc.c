/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:31:14 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 02:32:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_address(t_fmt *fmt)
{
	fmt->flag[hash] = 1;
	if (ft_print_integer(fmt) == ERROR)
		return (ERROR);
	return (0);
}

int				ft_print_count(t_fmt *fmt)
{
	if (fmt->len == 0)
		*(va_arg(fmt->ap, t_int *)) = fmt->rtn;
	else if (fmt->len == 'l')
		*(va_arg(fmt->ap, t_lint *)) = fmt->rtn;
	else if (fmt->len == 'L')
		*(va_arg(fmt->ap, t_llint *)) = fmt->rtn;
	else if (fmt->len == 'h')
		*(va_arg(fmt->ap, t_int *)) = (t_sint)fmt->rtn;
	else if (fmt->len == 'H')
		*(va_arg(fmt->ap, t_int *)) = (t_char)fmt->rtn;
	return (1);
}

int				ft_print_percent(t_fmt *fmt)
{
	char	c;
	int		lpad;
	int		zpad;
	int		rpad;

	c = '%';
	fmt->size = ft_max(1, fmt->wid);
	lpad = !fmt->flag[minus] && !fmt->flag[zero] ? fmt->size - 1 : 0;
	zpad = !fmt->flag[minus] && fmt->flag[zero] ? fmt->size - 1 : 0;
	rpad = fmt->flag[minus] ? fmt->size - 1 : 0;
	while (lpad--)
		fmt->rtn += write(1, " ", 1);
	while (zpad--)
		fmt->rtn += write(1, "0", 1);
	fmt->rtn += write(1, &c, 1);
	while (rpad--)
		fmt->rtn += write(1, " ", 1);
	return (0);
}

int				ft_print_etc(t_fmt *fmt)
{
	if (fmt->spec == 'p')
	{
		if (ft_print_address(fmt) == ERROR)
			return (ERROR);
	}
	else if (fmt->spec == 'n')
	{
		if (ft_print_count(fmt) == ERROR)
			return (ERROR);
	}
	else if (fmt->spec == '%')
	{
		if (ft_print_percent(fmt) == ERROR)
			return (ERROR);
	}
	return (0);
}
