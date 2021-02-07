/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating_f.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 12:04:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_round_up_f(t_big *big, t_fmt *fmt, int up, int head)
{
	fmt->prec = (fmt->prec == 0 && fmt->flag[dot] == 0) ? 6 : fmt->prec;
	head = big->idx_pnt + fmt->prec;
	if (head >= big->idx_nul)
		return ;
	if (head == big->idx_nul - 1)
		big->out[head] = (big->out[head - 1] - '0') & 1 ? '6' : '4';
	if (big->out[head] >= '5')
		up = 1;
	big->out[head] = '\0';
	while (up == 1 && --head >= 0 && (big->out[head] += 1))
	{
		up = 0;
		if (big->out[head] > '9' && (big->out[head] = '0'))
			up = 1;
	}
}

void			ft_trailing_zero_f(t_big *big, t_fmt *fmt)
{
	int			head;

	big->idx_g = fmt->prec;
	head = big->idx_pnt + fmt->prec - 1;
	while (head >= 0 && (big->out[head] == '\0'))
		head--;
	while (head >= 0 && (big->out[head] == '0'))
		head--;
	fmt->prec = ft_max(0, head - big->idx_pnt + 1);
	if (big->idx_pnt == 1 && fmt->prec < 1)
		fmt->prec = 0;
}

void			ft_decide_block_f(t_fmt *fmt, t_big *big, t_blk *blk, int sign)
{
	blk->nbr += big->out[0] != '0' ? 1 : 0;
	blk->nbr += big->len_i;
	blk->nbr += big->idx_pnt == 1 && big->out[0] == '0' ? 1 : 0;
	blk->nbr += fmt->prec || fmt->flag[hash] ? 1 : 0;
	blk->nbr += fmt->flag[hash] && big->is_g ? big->idx_g : fmt->prec;
	blk->minus += sign;
	blk->plus += (!sign && fmt->flag[plus]);
	blk->space += (!blk->plus && !blk->minus && fmt->flag[space]) ? 1 : 0;
	blk->pre = blk->plus + blk->minus + blk->space;
}

void			ft_write_f(t_big *big, t_fmt *fmt)
{
	int			i;

	i = (big->out[0] == '0');
	if (big->idx_pnt == 1 && big->out[0] == '0')
		fmt->rtn += write(1, "0", 1);
	while (i < big->idx_pnt)
		fmt->rtn += write(1, big->out + i++, 1);
	fmt->rtn += fmt->prec > 0 || fmt->flag[hash] > 0 ? write(1, ".", 1) : 0;
	if (fmt->prec || big->idx_g)
	{
		while (i < big->idx_pnt + fmt->prec && i < big->idx_nul)
			fmt->rtn += write(1, big->out + i++, 1);
		while (big->is_g && fmt->flag[hash] && i++ < big->idx_pnt + big->idx_g)
			fmt->rtn += write(1, "0", 1);
		while (!big->is_g && i++ < big->idx_pnt + fmt->prec)
			fmt->rtn += write(1, "0", 1);
	}
}
