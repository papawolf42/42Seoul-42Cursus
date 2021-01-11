/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:27:00 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/11 22:08:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*format2; // MUST DELETE

void	ft_reset_fmt(t_fmt *fmt)
{
	ft_bzero(fmt->flag, 6);
	fmt->spec = 0;
	ft_bzero(fmt->buff, 21);
	fmt->wid = 0;
	fmt->prec = 0;
	fmt->size = 0;
	fmt->len = 0;
}

void	ft_initialize_fmt(t_fmt *fmt, const char *format)
{
	fmt->str = format;
	fmt->rtn = 0;
	ft_reset_fmt(fmt);
}

void	ft_info_fmt(t_fmt *fmt) // MUST DELETE
{
	int 	i;

printf("\n\n==========\n info fmt\n==========\n");
	printf("format : %s\n", format2);
	printf("fmt->str : %s\n", fmt->str);
	i = -1;
	while (++i < 7)
		printf("fmt->flag[%d] : %d\n", i, fmt->flag[i]);
	printf("fmt->wid : %d\n", fmt->wid);
	printf("fmt->prec : %d\n", fmt->prec);
	printf("fmt->len : %d\n", fmt->len);
	printf("fmt->size : %d\n", fmt->size);
	printf("fmt->spec : %c\n", fmt->spec);
	printf("fmt->buff : %s\n", fmt->buff);
	printf("fmt->rtn : %d\n", fmt->rtn);
printf("==========\n end\n==========\n");
}

int		ft_print_iterative(t_fmt *fmt)
{
	while (*fmt->str != '\0')
	{
		if (ft_print_nonformat(fmt) == ERROR)
			return (ERROR);
		ft_reset_fmt(fmt);
		if (ft_parse_format(fmt) == ERROR)
			return (ERROR);
		if (ft_print_format(fmt) == ERROR)
			return (ERROR);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_fmt	fmt;
	
	format2 = format; // MUST DELETE
	va_start(fmt.ap, format);
	ft_initialize_fmt(&fmt, format);
	if(ft_print_iterative(&fmt) == ERROR)
		return (-1);
	va_end(fmt.ap);
	return (fmt.rtn);
}
