/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/04 11:41:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int				ft_is_inf_or_nan(t_fmt *fmt, t_dbl *dbl, t_big *big, int expo)
{
	if (expo == 1024 && dbl->s_dbl.mtsa != 0)
	{
		ft_print_string(fmt, "nan");
		return (1);
	}
	else if (expo == 1024 && dbl->s_dbl.mtsa == 0)
	{
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

int				ft_make_intg_dp(char intg_dp[][309], int max, int expo)
{
	char		num;
	char		up;
	int			i;

	while (max < expo)
	{
		up = 0;
		i = -1;
		while (intg_dp[max][++i] != '\0')
		{
			num = (intg_dp[max][i] - '0') * 2 + up;
			intg_dp[max + 1][i] = (num > 9) ? num - 10 + '0' : num + '0';
			up = (num > 9) ? 1 : 0;
		}
		if (up == 1)
			intg_dp[max + 1][i] = '1';
		max++;
	}
	return (max);
}

void			ft_sum_intg_dp(t_big *big, char intg_dp[][309], int i, int k)
{
	char		rock;
	char		egg;
	int			j;
	int			up;

	i = ft_max(big->expo - 53, -1);
	k = ft_max(51 - big->expo, -1);
	while (++i <= big->expo)
	{
		if (big->mtsa[++k] - '0')
		{
			up = 0;
			j = -1;
			while (intg_dp[i][++j] != '\0')
			{
				rock = big->intg[j] == '\0' ? 0 : big->intg[j] - '0';
				egg = (intg_dp[i][j] - '0') + rock + up;
				big->intg[j] = (egg > 9) ? egg - 10 + '0' : egg + '0';
				up = (egg > 9) ? 1 : 0;
			}
			if (up == 1)
				big->intg[j] = '1';
		}
	}
	big->len_i = ft_strlen(big->intg);
}

void			ft_get_integer(t_big *big)
{
	static int	exist_max;
	static char	intg_dp[1024][309] = {"1", };

	if (exist_max < big->expo)
		exist_max = ft_make_intg_dp(intg_dp, exist_max, big->expo);
	ft_sum_intg_dp(big, intg_dp, 0, 0);
}

int				ft_make_frac_dp(char frac_dp[][1077], int max, int expo)
{
	char		up;
	int			i;

	while (max < expo)
	{
		up = 0;
		i = -1;
		while (frac_dp[max][++i] != '\0')
		{
			frac_dp[max + 1][i] = ((frac_dp[max][i] - '0') >> 1) + up + '0';
			up = frac_dp[max][i] - '0' & 1 ? 5 : 0;
		}
		if (up == 5)
			frac_dp[max + 1][i] = '5';
		max++;
	}
	return (max);
}

void			ft_sum_frac_dp(t_big *big, char frac_dp[][1077], int i, int k)
{
	char		rock;
	char		egg;
	int			j;
	int			up;

	i = ft_max(-1 * big->expo - 2, -1);
	k = ft_min(53, -1 * big->expo + 52);
	while (++i < -1 * big->expo + 52)
	{
		up = 0;
		j = i + 1;
		if (big->mtsa[--k] - '0')
		{
			while (j--)
			{
				rock = big->frac[j] == '\0' ? 0 : big->frac[j] - '0';
				egg = (frac_dp[i][j] - '0') + rock + up;
				big->frac[j] = (egg > 9) ? egg - 10 + '0' : egg + '0';
				up = (egg > 9) ? 1 : 0;
			}
		}
	}
	big->len_f = ft_strlen(big->frac);
}

void			ft_get_fraction(t_big *big)
{
	static int	exist_max;
	static char	frac_dp[1075][1077] = {"5", };

	if (exist_max < -1 * big->expo + 51)
		exist_max = ft_make_frac_dp(frac_dp, exist_max, -1 * big->expo + 51);
	ft_sum_frac_dp(big, frac_dp, big->expo, -1);
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

void			ft_get_info_g(t_big *big, t_fmt *fmt)
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

// (round : 1)(integer)(point)(fraction)(more precision)

void			ft_decide_block_nbr(t_fmt *fmt, t_big *big, t_blk *blk, int sign)
{
	blk->nbr += big->out[0] != '0' ? 1 : 0;
	blk->nbr += big->len_i;
	blk->nbr += big->idx_pnt == 1 && big->out[0] == '0' ? 1 : 0;
	blk->nbr += fmt->prec || fmt->flag[hash] ? 1 : 0;
	blk->nbr += fmt->flag[hash] ? 0 : fmt->prec;
	blk->nbr += fmt->flag[hash] ? big->idx_g : 0;
	blk->minus += sign;
	blk->plus += (!sign && fmt->flag[plus]);
	blk->space += (!blk->plus && !blk->minus && fmt->flag[space]) ? 1 : 0;
	blk->pre = blk->plus + blk->minus + blk->space;
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

int				ft_print_f(t_fmt *fmt, t_dbl *dbl, t_big *big, t_blk *blk)
{
	ft_round_up_f(big, fmt, 0, 0);
	if (big->is_g)
		ft_get_info_g(big, fmt);
	ft_decide_block_nbr(fmt, big, blk, dbl->s_dbl.sign);
	ft_decide_block_floating(fmt, blk);
	ft_write_floating(big, fmt, blk);
	return (0);
}

int				ft_zerolen(char *str)
{
	int			i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (i);
}

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

void			ft_make_e_part(t_big *big)
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
			big->out_e[i--]= nbr % 10 + '0';
			nbr /= 10;
		}
	}
	big->len_e = ft_strlen(big->out_e);
}

void			ft_decide_block_e(t_fmt *fmt, t_big *big, t_blk *blk, int sign)
{
	blk->nbr += fmt->prec + 1;
	blk->nbr += fmt->prec || fmt->flag[hash] ? 1 : 0;
	blk->nbr += big->len_e;
	big->out[0] = big->out[0]; // delete
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
	if (fmt->prec > 0)
	{
		while (i < big->idx_pnt_e + fmt->prec && i < big->idx_nul)
			fmt->rtn += write(1, big->out + i++, 1);
		while (i++ < big->idx_pnt_e + fmt->prec)
			fmt->rtn += write(1, "0", 1);
	}
	fmt->rtn += write(1, big->out_e, ft_strlen(big->out_e));
}

int				ft_print_e(t_fmt *fmt, t_dbl *dbl, t_big *big, t_blk *blk)
{
	ft_rount_up_e(big, fmt, 0, 0);
	ft_make_e_part(big);
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
	ft_get_integer(&big);
	ft_get_fraction(&big);
	ft_get_output(&big, big.len_i, big.len_f);
	if (fmt->spec == 'g')
		ft_redirect_to_fe(fmt, &big);
	if (fmt->spec == 'f')
		ft_print_f(fmt, &dbl, &big, &blk);
	else if (fmt->spec == 'e')
		ft_print_e(fmt, &dbl, &big, &blk);
	return (0);
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
