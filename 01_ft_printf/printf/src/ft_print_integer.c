/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/19 12:53:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_print_integer(t_fmt *fmt)
{
	t_blk		blk;

	ft_bzero(&blk, sizeof(blk));
	if (fmt->spec == 'd' || fmt->spec == 'i')
		if (ft_print_decimal(fmt, &blk) == ERROR)
			return (ERROR);
	// if (fmt->spec == 'u')
	// 	if (ft_print_unsigned(fmt, &blk) == ERROR)
	// 		return (ERROR);
	// if (fmt->spec == 'o')
	// 	if (ft_print_octal(fmt) == ERROR)
	// 		return (ERROR);
	// if (fmt->spec == 'x' || fmt->spec == 'X')
	// 	if (ft_print_hexadecimal(fmt) == ERROR)
	// 		return (ERROR);
	return (0);
}
