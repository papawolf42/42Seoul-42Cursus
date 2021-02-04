/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/04 19:10:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_base_unsigned(t_fmt *fmt)
{
	if (fmt->spec == 'u')
	{
		fmt->base = 10;
		fmt->cbase = CHARSET_DECI;
	}
	else if (fmt->spec == 'o')
	{
		fmt->base = 8;
		fmt->cbase = CHARSET_OCTA;
	}
	else if (fmt->spec == 'x' || fmt->spec == 'X' || fmt->spec == 'p')
	{
		fmt->base = 16;
		fmt->cbase = fmt->spec == 'X' ? CHARSET_HEXA_U : CHARSET_HEXA_L;
	}
	return (1);
}

int			ft_count_digit_signed(t_llint nbr)
{
	int			digit;
	t_ullint	multi;
	int			sign;

	digit = 0;
	multi = 1;
	sign = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		sign++;
	}
	while ((t_ullint)nbr >= multi)
	{
		multi *= 10;
		digit++;
	}
	return (sign + digit);
}

int			ft_count_digit_unsigned(t_ullint nbr, t_ullint base)
{
	int			digit;
	t_ullint	multi;

	digit = 0;
	multi = 1;
	if (nbr == 0)
		return (1);
	if (nbr >= base)
	{
		nbr /= base;
		digit++;
	}
	while (nbr >= multi)
	{
		multi *= base;
		digit++;
	}
	return (digit);
}

void		ft_itoa_signed(t_fmt *fmt, t_blk *blk)
{
	t_llint		nbr;
	int			i;

	nbr = fmt->nbr;
	if (nbr < 0 && (nbr *= -1))
		blk->minus = 1;
	blk->nbr = ft_count_digit_signed(nbr);
	if (blk->minus == 0 && fmt->flag[plus] > 0)
		blk->plus = 1;
	if (blk->minus == 0 && fmt->flag[space] > 0 && fmt->flag[plus] == 0)
		blk->space = 1;
	if (nbr == 0)
		blk->buff[0] = '0';
	i = blk->nbr;
	while (nbr >= 1 && (blk->buff[--i] = nbr % 10 + '0'))
		nbr /= 10;
	blk->pre = blk->plus + blk->minus + blk->space;
	blk->nbr = fmt->nbr == 0 && fmt->flag[dot] && fmt->prec == 0 ? 0 : blk->nbr;
}

void		ft_itoa_unsigned(t_fmt *fmt, t_blk *blk)
{
	t_ullint		unbr;
	int				i;

	unbr = fmt->unbr;
	blk->nbr = ft_count_digit_unsigned(unbr, fmt->base);
	if (fmt->flag[plus] > 0)
		blk->plus = 1;
	if (fmt->flag[space] > 0 && fmt->flag[plus] == 0)
		blk->space = 1;
	if (unbr == 0)
		blk->buff[0] = '0';
	i = blk->nbr;
	while (unbr >= 1 && (blk->buff[--i] = fmt->cbase[unbr % fmt->base]))
		unbr /= fmt->base;
	if (fmt->spec == 'u' && fmt->flag[hash])
		blk->prefix = 0;
	else if (fmt->spec == 'o' && fmt->flag[hash])
		blk->prefix = 1;
	else if ((fmt->flag[hash] && fmt->unbr != 0) || fmt->spec == 'p')
		blk->prefix = 2;
	blk->pre = blk->prefix + blk->minus + blk->plus + blk->space;
	blk->nbr = !fmt->unbr && fmt->flag[dot] && fmt->prec == 0 ? 0 : blk->nbr;
}
