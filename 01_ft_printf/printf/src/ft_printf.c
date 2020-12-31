/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:27:00 by gunkim            #+#    #+#             */
/*   Updated: 2020/12/06 17:51:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_fmt(t_fmt *fmt)
{
	bzero(fmt->flag, 6);
	fmt->spec = 0;
	bzero(fmt->buff, 21);
	fmt->wid = 0;
	fmt->pre = 0;
	fmt->len = 0;
}

void	ft_initialize_fmt(t_fmt *fmt, const char *format, va_list ap)
{
	fmt->str = format;
	fmt->ap = ap;
	fmt->rtn = 0;
	ft_reset_fmt(fmt);
}

int		ft_print_iterative(t_fmt *fmt)
{
	if (ft_print_nonformat(fmt) == ERROR)
		return (ERROR);
	if (ft_parse_format(fmt) == ERROR)
		return (ERROR);
	if (!ft_print_process(fmt) == ERROR)
		return (ERROR);
	if (!ft_print_format(fmt) == ERROR)
		return (ERROR);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_fmt	fmt;
	va_list	ap;
	
	va_start(ap, format);
	ft_initialize_fmt(&fmt, format, ap);
	if(ft_print_iterative(&fmt) == ERROR)
		return (-1);
	return (fmt->rtn);
}

int		main(void)
{
	char	name[] = "gunkim";
	int		age = 13;

	ft_printf("내 이름은 %s, %d살 이에요.", name, age);
}
