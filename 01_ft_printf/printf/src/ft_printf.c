/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:27:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/09 19:55:24 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_fmt(t_fmt *fmt)
{
	ft_bzero(fmt->flag, 6);
	fmt->spec = 0;
	ft_bzero(fmt->buff, 21);
	fmt->wid = 0;
	fmt->prec = 0;
	fmt->len = 0;
}

void	ft_initialize_fmt(t_fmt *fmt, const char *format)
{
	fmt->str = format;
	fmt->rtn = 0;
	ft_reset_fmt(fmt);
}

int		ft_print_iterative(t_fmt *fmt)
{
	if (ft_print_nonformat(fmt) == ERROR)
		return (ERROR);
	if (ft_parse_format(fmt) == ERROR)
		return (ERROR);
//	if (ft_print_process(fmt) == ERROR)
//		return (ERROR);
//	if (ft_print_format(fmt) == ERROR)
//		return (ERROR);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_fmt	fmt;
	
	va_start(fmt.ap, format);
	ft_initialize_fmt(&fmt, format);
	if(ft_print_iterative(&fmt) == ERROR)
		return (-1);
	va_end(fmt.ap);
	return (fmt.rtn);
}
