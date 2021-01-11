/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:28:17 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/11 02:13:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_print_format(t_fmt *fmt)
{
	if (fmt->spec == 'd' || fmt->spec == 'i' || fmt->spec == 'u' ||
			 fmt->spec == 'o' || fmt->spec == 'x' || fmt->spec == 'X')
		if(ft_print_integer(fmt) == ERROR)
			return (ERROR);
	/*
	if (fmt->spec == 'f' || fmt->spec == 'e' || fmt->spec == 'g')
		if (ft_print_float(fmt) == ERROR)
			return (ERROR);
	if (fmt->spec == 'c' || fmt->spec == 's')
		if (ft_print_letter(fmt) == ERROR)
			return (ERROR);
	if (fmt->spec == 'p')
		if (ft_print_address(fmt) == ERROR)
			return (ERROR);
	if (fmt->spec == 'n')
		if (ft_print_count(fmt) == ERROR)
			return (ERROR);
	if (fmt->spec == '%')
		if (ft_print_percent(fmt) == ERROR)
			return (ERROR);
	*/
	return (0);
}
