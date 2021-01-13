/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/13 16:01:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_itoa_custom(t_fmt *fmt, t_blk *blk)
{
	t_llint		nbr;
	int			i;

	nbr = va_arg(fmt->ap, int);
	if (nbr < 0 && (nbr *= -1))
		blk->minus = 1;
	blk->nbr = ft_count_digit(nbr);
	if (blk->minus == 0 && fmt->flag[plus] > 0 && fmt->flag[space] == 0)
		blk->plus = 1;
	if (blk->minus == 0 && fmt->flag[space] > 0 && fmt->flag[plus] == 0)
		blk->space = 1;
	i = blk->nbr;
	while (nbr >= 1)
	{
		blk->buff[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	//ft_get_prefix
	blk->pre = blk->prefix + blk->plus + blk->minus + blk->space;
}

int			ft_get_out(t_fmt *fmt, t_blk *blk)
{
	int		head;
	char	*letter;

	head = 0;
	letter = fmt->flag[zero] && !blk->minus ? "0" : " ";
		while (blk->lpad--)
			fmt->rtn += write(1, letter, 1);
		fmt->rtn += write(1, "+", blk->plus);
		fmt->rtn += write(1, "-", blk->minus);
		fmt->rtn += write(1, " ", blk->space);
		while (blk->prec--)
			fmt->rtn += write(1, "0", 1);
		fmt->rtn += write(1, blk->buff, blk->nbr);
		while (blk->rpad--)
			fmt->rtn += write(1, " ", 1);
	return (0);
}

int			ft_get_index(t_fmt *fmt, t_blk *blk)
{
	ft_itoa_custom(fmt, blk);
	blk->prec = ft_max(0, fmt->prec - blk->nbr);
	fmt->size = ft_max(blk->nbr, ft_max(fmt->wid, fmt->prec));
	if (fmt->flag[minus] == 0)
		blk->lpad = ft_max(0, fmt->size - blk->pre - blk->prec - blk->nbr);
	if (fmt->flag[minus] > 0)
		blk->rpad = ft_max(0, fmt->size - blk->pre - blk->prec - blk->nbr);
	if(ft_get_out(fmt, blk) == ERROR)
		return (ERROR);
	return (0);
}

int			ft_print_decimal(t_fmt *fmt, t_blk *blk)
{
	ft_get_index(fmt, blk);
	return (0);
}

int			ft_print_integer(t_fmt *fmt)
{
	t_blk		blk;

	ft_bzero(&blk, sizeof(blk));
	if (fmt->spec == 'd' || fmt->spec == 'i')
		if (ft_print_decimal(fmt, &blk) == ERROR)
			return (ERROR);
	// if (fmt->spec == 'u')
	// 	if (ft_print_unsigned(fmt) == ERROR)
	// 		return (ERROR);
	// if (fmt->spec == 'o')
	// 	if (ft_print_octal(fmt) == ERROR)
	// 		return (ERROR);
	// if (fmt->spec == 'x' || fmt->spec == 'X')
	// 	if (ft_print_hexadecimal(fmt) == ERROR)
	// 		return (ERROR);
	return (0);
}