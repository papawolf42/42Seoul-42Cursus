/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating_common.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 12:03:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_zerolen(char *str)
{
	int			i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (i);
}

void			ft_get_output(t_big *big, int len_i, int len_f)
{
	int			idx;

	big->out[0] = '0';
	idx = 0;
	while (len_i)
		big->out[++idx] = big->intg[--len_i];
	big->idx_pnt = idx + 1;
	while (len_i < len_f)
		big->out[++idx] = big->frac[len_i++];
	big->idx_nul = idx + 1;
}

void			ft_redirect_to_fe(t_fmt *fmt, t_big *big)
{
	int			p;
	int			x;
	t_big		big_temp;
	t_fmt		fmt_temp;

	big_temp = *big;
	fmt_temp = *fmt;
	big->is_g = 1;
	p = fmt->flag[dot] && fmt->prec == 0 ? 1 : fmt->prec;
	p = p == 0 ? 6 : p;
	fmt_temp.prec = fmt_temp.prec < 1 ? 0 : p - 1;
	x = ft_rount_up_e(&big_temp, &fmt_temp, 0, 0);
	if (p > x && x >= -4)
	{
		fmt->spec = 'f';
		fmt->prec = p - (x + 1);
		return ;
	}
	else
	{
		fmt->spec = 'e';
		fmt->prec = p - 1;
		return ;
	}
}

int				ft_decide_block_floating(t_fmt *fmt, t_blk *blk)
{
	blk->prec = ft_max(0, fmt->prec - blk->nbr);
	fmt->size = ft_max(blk->nbr + blk->prec, ft_max(fmt->wid, fmt->prec));
	blk->pad = ft_max(0, fmt->size - blk->pre - blk->prec - blk->nbr);
	if (!fmt->flag[minus])
	{
		if (!fmt->flag[zero])
			blk->lpad = blk->pad;
		else if (fmt->flag[zero])
			blk->zero = blk->pad;
	}
	else if (fmt->flag[minus])
		blk->rpad = blk->pad;
	return (0);
}

void			ft_write_floating(t_big *big, t_fmt *fmt, t_blk *blk)
{
	while (blk->lpad--)
		fmt->rtn += write(1, " ", 1);
	if (fmt->spec == 'x')
		fmt->rtn += write(1, "0x", blk->prefix);
	else
		fmt->rtn += write(1, "0X", blk->prefix);
	fmt->rtn += write(1, "+", blk->plus);
	fmt->rtn += write(1, "-", blk->minus);
	fmt->rtn += write(1, " ", blk->space);
	while (blk->zero--)
		fmt->rtn += write(1, "0", 1);
	while (blk->prec--)
		fmt->rtn += write(1, "0", 1);
	if (fmt->spec == 'f')
		ft_write_f(big, fmt);
	else if (fmt->spec == 'e')
		ft_write_e(big, fmt);
	while (blk->rpad--)
		fmt->rtn += write(1, " ", 1);
}
