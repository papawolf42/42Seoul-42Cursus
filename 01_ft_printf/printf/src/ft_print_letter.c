/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:11:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/31 20:05:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_character(t_fmt *fmt)
{
	char	c;
	int		lpad;
	int		rpad;

	c = (char)va_arg(fmt->ap, int);
	fmt->size = ft_max(1, fmt->wid);
	lpad = fmt->flag[minus] ? 0 : fmt->size - 1;
	rpad = fmt->flag[minus] ? fmt->size - 1 : 0;
	while (lpad--)
		fmt->rtn += write(1, " ", 1);
	fmt->rtn += write(1, &c, 1);
	while (rpad--)
		fmt->rtn += write(1, " ", 1);
	return (0);
}

int			ft_print_string(t_fmt *fmt, char *s)
{
	int		out;
	int		lpad;
	int		rpad;

	if (s == NULL)
		s = CHARSET_NULL;
	out = fmt->flag[dot] ? ft_min(ft_strlen(s), fmt->prec) : ft_strlen(s);
	fmt->size = ft_max(out, fmt->wid);
	lpad = fmt->flag[minus] ? 0 : fmt->size - out;
	rpad = fmt->flag[minus] ? fmt->size - out : 0;
	while (lpad--)
		fmt->rtn += write(1, " ", 1);
	fmt->rtn += write(1, s, out);
	while (rpad--)
		fmt->rtn += write(1, " ", 1);
	return (0);
}

int			ft_print_letter(t_fmt *fmt)
{
	if (fmt->spec == 'c')
		if (ft_print_character(fmt) == ERROR)
			return (ERROR);
	if (fmt->spec == 's')
		if (ft_print_string(fmt, va_arg(fmt->ap, char *)) == ERROR)
			return (ERROR);
	return (0);
}
