/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/04 19:11:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			ft_decide_block(t_fmt *fmt, t_blk *blk)
{
	blk->prec = ft_max(0, fmt->prec - blk->nbr);
	fmt->size = ft_max(blk->nbr + blk->prec, ft_max(fmt->wid, fmt->prec));
	blk->pad = ft_max(0, fmt->size - blk->pre - blk->prec - blk->nbr);
	if (!fmt->flag[minus])
	{
		if (!fmt->flag[zero])
			blk->lpad = blk->pad;
		else if (fmt->flag[zero] && !fmt->flag[dot])
			blk->zero = blk->pad;
		else if (fmt->flag[zero] && fmt->flag[dot])
			blk->lpad = blk->pad;
	}
	else if (fmt->flag[minus])
		blk->rpad = blk->pad;
	return (0);
}

int			ft_write_integer(t_fmt *fmt, t_blk *blk)
{
	while (blk->lpad--)
		fmt->rtn += write(1, " ", 1);
	if (fmt->spec == 'X')
		fmt->rtn += write(1, "0X", blk->prefix);
	else
		fmt->rtn += write(1, "0x", blk->prefix);
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
	{
		ft_len_signed(fmt);
		ft_itoa_signed(fmt, &blk);
		ft_decide_block(fmt, &blk);
		if (ft_write_integer(fmt, &blk) == ERROR)
			return (ERROR);
	}
	if (fmt->spec == 'u' || fmt->spec == 'o' ||
		fmt->spec == 'x' || fmt->spec == 'X' || fmt->spec == 'p')
	{
		if (fmt->spec == 'p')
			fmt->unbr = (t_ullint)va_arg(fmt->ap, void *);
		else
			ft_len_unsigned(fmt);
		ft_base_unsigned(fmt);
		ft_itoa_unsigned(fmt, &blk);
		ft_decide_block(fmt, &blk);
		if (ft_write_integer(fmt, &blk) == ERROR)
			return (ERROR);
	}
	return (0);
}
