/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/19 12:52:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_len_id(t_fmt *fmt)
{
	if (fmt->len == 0 || fmt->len == 'h' || fmt->len == 'H')
		fmt->nbr = va_arg(fmt->ap, int);
	else if (fmt->len == 'l')
		fmt->nbr = va_arg(fmt->ap, t_lint);
	else if (fmt->len == 'L')
		fmt->nbr = va_arg(fmt->ap, t_llint);
	if (fmt->len == 0)
		fmt->nbr = (int)fmt->nbr;
	else if (fmt->len == 'h')
		fmt->nbr = (t_sint)fmt->nbr;
	else if (fmt->len == 'H')
		fmt->nbr = (char)fmt->nbr;
}

void		ft_itoa_id(t_fmt *fmt, t_blk *blk)
{
	t_llint		nbr;
	int			i;

	nbr = fmt->nbr;
	if (nbr < 0 && (fmt->nbr *= -1))
		blk->minus = 1;
	blk->nbr = ft_count_digit(nbr);
	if (blk->minus == 0 && fmt->flag[plus] > 0 && fmt->flag[space] == 0)
		blk->plus = 1;
	if (blk->minus == 0 && fmt->flag[space] > 0 && fmt->flag[plus] == 0)
		blk->space = 1;
	if (nbr == 0)
		blk->buff[0] = '0';
	i = blk->nbr;
	while (nbr >= 1 && (blk->buff[--i] = nbr % 10 + '0'))
		nbr /= 10;
	blk->pre = blk->prefix + blk->plus + blk->minus + blk->space;
}

int			ft_decide_block_id(t_fmt *fmt, t_blk *blk)
{
	blk->prec = ft_max(0, fmt->prec - blk->nbr);
	blk->nbr = fmt->nbr == 0 && fmt->flag[dot] && fmt->prec == 0 ? 0 : blk->nbr;
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

int			ft_write_id(t_fmt *fmt, t_blk *blk)
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

int			ft_print_decimal(t_fmt *fmt, t_blk *blk)
{
	ft_len_id(fmt);
	ft_itoa_id(fmt, blk);
	ft_decide_block_id(fmt, blk);
	if(ft_write_id(fmt, blk) == ERROR)
		return (ERROR);
	return (0);
}
