/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating_e.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 12:14:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_rount_up_e(t_big *big, t_fmt *fmt, int up, int head)
{
	fmt->prec = (fmt->prec == 0 && fmt->flag[dot] == 0) ? 6 : fmt->prec;
	big->idx_pnt_e = big->is_zero ? 1 : ft_zerolen(big->out) + 1;
	big->int_e = big->idx_pnt - big->idx_pnt_e;
	head = big->idx_pnt_e + fmt->prec;
	if (head >= big->idx_nul)
		return (big->int_e);
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
	if (big->idx_pnt_e - 2 >= 0 && big->out[big->idx_pnt_e - 2] == '1')
	{
		big->idx_pnt_e--;
		big->int_e++;
	}
	return (big->int_e);
}

void			ft_get_output_e(t_big *big)
{
	int			nbr;
	int			sign;
	int			digit;
	int			i;

	nbr = big->int_e;
	sign = 0;
	if (nbr < 0 && (sign = 1))
		nbr *= -1;
	digit = ft_count_digit_signed(nbr);
	big->out_e[0] = 'e';
	big->out_e[1] = sign == 0 ? '+' : '-';
	big->out_e[2] = '0';
	if (digit == 1)
		big->out_e[3] = nbr % 10 + '0';
	else
	{
		i = digit + 1;
		while (digit--)
		{
			big->out_e[i--] = nbr % 10 + '0';
			nbr /= 10;
		}
	}
	big->len_e = ft_strlen(big->out_e);
}

void			ft_trailing_zero_e(t_big *big, t_fmt *fmt)
{
	int			head;

	big->idx_g = fmt->prec;
	head = big->idx_pnt_e + fmt->prec - 1;
	while (head >= 0 && (big->out[head] == '\0'))
		head--;
	while (head >= 0 && (big->out[head] == '0'))
		head--;
	fmt->prec = ft_max(0, head - big->idx_pnt_e + 1);
	if (big->idx_pnt == 1 && fmt->prec < 1)
		fmt->prec = 0;
}

void			ft_decide_block_e(t_fmt *fmt, t_big *big, t_blk *blk, int sign)
{
	blk->nbr += fmt->prec + 1;
	blk->nbr += fmt->prec || fmt->flag[hash] ? 1 : 0;
	blk->nbr += big->len_e;
	blk->minus += sign;
	blk->plus += (!sign && fmt->flag[plus]);
	blk->space += (!blk->plus && !blk->minus && fmt->flag[space]) ? 1 : 0;
	blk->pre = blk->plus + blk->minus + blk->space;
}

void			ft_write_e(t_big *big, t_fmt *fmt)
{
	int			i;

	i = big->idx_pnt_e - 1;
	fmt->rtn += write(1, big->out + i++, 1);
	fmt->rtn += fmt->prec || fmt->flag[hash] ? write(1, ".", 1) : 0;
	if (fmt->prec || big->idx_g)
	{
		while (i < big->idx_pnt_e + fmt->prec && i < big->idx_nul)
			fmt->rtn += write(1, big->out + i++, 1);
		while (big->is_g && fmt->flag[hash]
		&& i++ < big->idx_pnt_e + big->idx_g)
			fmt->rtn += write(1, "0", 1);
		while (!big->is_g && i++ < big->idx_pnt_e + fmt->prec)
			fmt->rtn += write(1, "0", 1);
	}
	fmt->rtn += write(1, big->out_e, ft_strlen(big->out_e));
}
