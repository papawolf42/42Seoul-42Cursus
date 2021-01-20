/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/19 22:34:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_len_signed(t_fmt *fmt)
{
	if (fmt->len == 0 || fmt->len == 'h' || fmt->len == 'H')
		fmt->nbr = va_arg(fmt->ap, t_int);
	else if (fmt->len == 'l')
		fmt->nbr = va_arg(fmt->ap, t_lint);
	else if (fmt->len == 'L')
		fmt->nbr = va_arg(fmt->ap, t_llint);
	if (fmt->len == 0)
		fmt->nbr = (t_int)fmt->nbr;
	else if (fmt->len == 'h')
		fmt->nbr = (t_sint)fmt->nbr;
	else if (fmt->len == 'H')
		fmt->nbr = (t_char)fmt->nbr;
}

void		ft_len_unsigned(t_fmt *fmt)
{
	if (fmt->len == 0 || fmt->len == 'h' || fmt->len == 'H')
		fmt->unbr = va_arg(fmt->ap, t_uint);
	else if (fmt->len == 'l')
		fmt->unbr = va_arg(fmt->ap, t_ulint);
	else if (fmt->len == 'L')
		fmt->unbr = va_arg(fmt->ap, t_ullint);
	if (fmt->len == 0)
		fmt->unbr = (t_uint)fmt->unbr;
	else if (fmt->len == 'h')
		fmt->unbr = (t_usint)fmt->unbr;
	else if (fmt->len == 'H')
		fmt->unbr = (t_uchar)fmt->unbr;
}

int			ft_write_integer(t_fmt *fmt, t_blk *blk)
{
	int		head;
	char	*letter;

	head = 0;
	letter = fmt->flag[zero] && !blk->minus ? "0" : " ";
		while (blk->lpad--)
			fmt->rtn += write(1, " ", 1);
		fmt->rtn += write(1, "+", blk->plus);
		fmt->rtn += write(1, "-", blk->minus);
		fmt->rtn += write(1, " ", blk->space);
		while (blk->zero--)
			fmt->rtn += write(1, "0", 1);
		while (blk->prec--)
			fmt->rtn += write(1, "0", 1);
		fmt->rtn += write(1, blk->buff, blk->nbr);
		while (blk->rpad--)
			fmt->rtn += write(1, " ", 1);
	return (0);
}

int			ft_print_integer(t_fmt *fmt)
{
	t_blk		blk;

	ft_bzero(&blk, sizeof(blk));
	if (fmt->spec == 'd' || fmt->spec == 'i')
		if (ft_print_decimal(fmt, &blk) == ERROR)
			return (ERROR);
	if (fmt->spec == 'u')
		if (ft_print_unsigned(fmt, &blk) == ERROR)
			return (ERROR);
	if (fmt->spec == 'o')
		if (ft_print_octal(fmt, &blk) == ERROR)
			return (ERROR);
	// if (fmt->spec == 'x' || fmt->spec == 'X')
	// 	if (ft_print_hexadecimal(fmt) == ERROR)
	// 		return (ERROR);
	return (0);
}
