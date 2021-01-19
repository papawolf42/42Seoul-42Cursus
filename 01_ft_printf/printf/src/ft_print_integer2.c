/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/19 19:12:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_itoa_id(t_fmt *fmt, t_blk *blk)
{
	t_llint		nbr;
	int			i;

	nbr = fmt->nbr;
	if (nbr < 0 && (nbr *= -1))
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

int			ft_print_decimal(t_fmt *fmt, t_blk *blk)
{
	ft_len_signed(fmt);
	ft_itoa_id(fmt, blk);
	ft_decide_block_id(fmt, blk);
	if(ft_write_integer(fmt, blk) == ERROR)
		return (ERROR);
	return (0);
}
