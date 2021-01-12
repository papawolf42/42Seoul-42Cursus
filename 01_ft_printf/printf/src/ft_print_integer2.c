/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:00:41 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/12 15:13:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_itoa_custom(t_fmt *fmt, t_blk *blk)
{
	llint		temp;
	int			i;

	temp = va_arg(fmt->ap, int);
	if (temp < 0)
	{
		temp *= -1;
		blk->minus = 1;
	}
	blk->nbr = ft_count_digit(temp);
	if (temp > 0 && fmt->flag[plus] > 0 && fmt->flag[space] == 0)
		blk->plus = 1;
	if (temp > 0 && fmt->flag[space] > 0 && fmt->flag[plus] == 0)
		blk->space = 1;
	i = blk->nbr;
	while (temp >= 1)
	{
		blk->buff[--i] = temp % 10 + '0';
		temp /= 10;
	}
	//ft_get_prefix
	blk->pre = blk->prefix + blk->plus + blk->minus + blk->space;
}

int			ft_get_out(t_fmt *fmt, t_blk *blk)
{
	int		head;
	char	*letter;

	head = 0;
	letter = fmt->flag[minus] == 0 && fmt->flag[zero] > 0 ? "0" : " ";
	while (blk->lpad--)
		write(1, letter, 1);
	while (blk->plus--)
		write(1, "+", 1);
	while (blk->minus--)
		write(1, "-", 1);
	while (blk->space--)
		write(1, " ", 1);
	while (blk->prec--)
		write(1, "0", 1);
	write(1, blk->buff, blk->nbr);
	while (blk->rpad--)
		write(1, " ", 1);
	fmt->rtn += fmt->size;
	return (0);
}

int			ft_get_index(t_fmt *fmt, t_blk *blk)
{
	ft_itoa_custom(fmt, blk);
	fmt->size = ft_max(blk->nbr, ft_max(fmt->wid, fmt->prec));
	blk->prec = ft_max(0, fmt->prec - blk->nbr);
	if (fmt->flag[minus] == 0)
		blk->lpad = ft_max(0, fmt->size - blk->pre - blk->nbr);
	if (fmt->flag[minus] > 0)
		blk->rpad = ft_max(0, fmt->size - blk->pre - blk->nbr);
	if(ft_get_out(fmt, blk) == ERROR)
		return (ERROR);
	return (0);
}

int			ft_print_decimal(t_fmt *fmt, t_blk *blk)
{
	ft_get_index(fmt, blk);
	return (0);
}

/*
int			ft_print_decimal(t_fmt *fmt)
{
	int			decimal;
	char		*base;
	char		*temp;
	int			size;
	int			i;
	
	decimal = va_arg(fmt->ap, int);
	base = ft_itoa(decimal);
	size = ft_strlen(base);
	if (fmt->flag[plus] == 1 && decimal > 0)
	{
		temp = ft_strjoin("+", base);
		free(base);
		base = temp;
		size++;
	}
	fmt->size = ft_max(size, ft_max(fmt->wid, fmt->prec));
	i = fmt->prec - size;
	while (i-- > 0)
	{
		temp = ft_strjoin("0", base);
		free(base);
		base = temp;
		size++;
	}
	if (fmt->flag[minus] > 0)
	{
		ft_strlcat(fmt->buff, base, size + 1);
	}
	else
	{
		i = fmt->size - size;
		while (i-- > 0)
		{
			temp = ft_strjoin(" ", base);
			free(base);
			base = temp;
			size++;
		}
		ft_strlcat(fmt->buff, base, size + 1);
	}
	fmt->rtn += write(1, fmt->buff, fmt->size);
	return (0);
}
*/

void		ft_initialize_blk(t_blk *blk)
{
	ft_bzero(blk->buff, 33);
	blk->rpad = 0;
	blk->nbr = 0;
	blk->prec = 0;
	blk->space = 0;
	blk->minus = 0;
	blk->plus = 0;
	blk->prefix = 0;
	blk->pre = 0;
	blk->lpad = 0;
}

int			ft_print_integer(t_fmt *fmt)
{
	t_blk		blk;

	ft_initialize_blk(&blk);
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
