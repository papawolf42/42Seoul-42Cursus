/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 12:07:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_is_inf_or_nan(t_fmt *fmt, t_dbl *dbl, t_big *big, int expo)
{
	if (expo == 1024 && dbl->s_dbl.mtsa != 0)
	{
		fmt->flag[zero] = 0;
		ft_print_string(fmt, "nan");
		return (1);
	}
	else if (expo == 1024 && dbl->s_dbl.mtsa == 0)
	{
		fmt->flag[zero] = 0;
		if (dbl->s_dbl.sign)
			ft_print_string(fmt, "-inf");
		else if (fmt->flag[plus])
			ft_print_string(fmt, "+inf");
		else if (fmt->flag[space])
			ft_print_string(fmt, " inf");
		else
			ft_print_string(fmt, "inf");
		return (1);
	}
	big->len_f = 0;
	return (0);
}

void			ft_get_52_bit(t_dbl *dbl, t_big *big)
{
	int				i;
	const size_t	mantissa = dbl->s_dbl.mtsa;

	big->is_zero = mantissa == 0 && dbl->s_dbl.expo == 0 ? 1 : 0;
	big->mtsa[52] = big->is_zero ? '0' : '1';
	i = 52;
	while (i--)
		big->mtsa[i] = (((mantissa >> i) & 1) > 0) + '0';
}

int				ft_print_f(t_fmt *fmt, t_dbl *dbl, t_big *big, t_blk *blk)
{
	ft_round_up_f(big, fmt, 0, 0);
	if (big->is_g)
		ft_trailing_zero_f(big, fmt);
	ft_decide_block_f(fmt, big, blk, dbl->s_dbl.sign);
	ft_decide_block_floating(fmt, blk);
	ft_write_floating(big, fmt, blk);
	return (0);
}

int				ft_print_e(t_fmt *fmt, t_dbl *dbl, t_big *big, t_blk *blk)
{
	ft_rount_up_e(big, fmt, 0, 0);
	ft_get_output_e(big);
	if (big->is_g)
		ft_trailing_zero_e(big, fmt);
	ft_decide_block_e(fmt, big, blk, dbl->s_dbl.sign);
	ft_decide_block_floating(fmt, blk);
	ft_write_floating(big, fmt, blk);
	return (0);
}

int				ft_print_floating(t_fmt *fmt)
{
	t_dbl		dbl;
	t_big		big;
	t_blk		blk;

	dbl.val = va_arg(fmt->ap, double);
	ft_bzero(&big, sizeof(big));
	ft_bzero(&blk, sizeof(blk));
	big.expo = dbl.s_dbl.expo - 1023;
	if (ft_is_inf_or_nan(fmt, &dbl, &big, big.expo))
		return (0);
	ft_get_52_bit(&dbl, &big);
	ft_get_decimal_from_52bit(&big);
	ft_get_output(&big, big.len_i, big.len_f);
	if (fmt->spec == 'g')
		ft_redirect_to_fe(fmt, &big);
	if (fmt->spec == 'f')
		ft_print_f(fmt, &dbl, &big, &blk);
	else if (fmt->spec == 'e')
		ft_print_e(fmt, &dbl, &big, &blk);
	return (0);
}
