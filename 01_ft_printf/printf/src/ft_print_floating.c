/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/30 19:04:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_get_52_bit(size_t mantissa, t_big *big)
{
	int			i;

	big->mtsa[52] = '1';
	i = 52;
	while (i--)
		big->mtsa[i] = (((mantissa >> i) & 1) > 0) + '0';
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

// f가 따로 들어오지 않으면, prec은 6
// 정밀도가 0으로 취급하는 것 -> 음수의 정밀도, .만 찍힌 경우, .0
// %.-1f, %.f, %.0f

void			ft_round_up(t_big *big, t_fmt *fmt, int up, int head)
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
	ft_write_flt(big, fmt);
	while (blk->rpad--)
		fmt->rtn += write(1, " ", 1);
}

// (round : 1)(integer)(point)(fraction)(more precision)

void			ft_decide_block_nbr(t_big *big, t_fmt *fmt, t_blk *blk, int sign)
{
	blk->nbr += big->out[0] != '0' ? 1 : 0;
	blk->nbr += big->idx_pnt == 1 && big->out[0] == '0' ? 1 : 0;
	blk->nbr += big->len_i;
	blk->nbr += fmt->prec || fmt->flag[hash] ? 1 : 0;
	blk->nbr += fmt->prec;
	blk->minus += sign;
	blk->plus += (!sign && fmt->flag[plus]);
	blk->space += fmt->flag[space] ? 1 : 0;
	blk->pre = blk->plus + blk->minus + blk->space;
}

int			ft_decide_block_floating(t_fmt *fmt, t_blk *blk)
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

void			ft_write_flt(t_big *big, t_fmt *fmt)
{
	int			i;

	i = (big->out[0] == '0');
	if (big->idx_pnt == 1 && big->out[0] == '0')
		fmt->rtn += write(1, "0", 1);
	while (i < big->idx_pnt)
		fmt->rtn += write(1, big->out + i++, 1);
	fmt->rtn += fmt->prec > 0 || fmt->flag[hash] > 0 ? write(1, ".", 1) : 0;
	if (fmt->prec > 0)
	{
		while (i < big->idx_pnt + fmt->prec && i < big->idx_nul)
			fmt->rtn += write(1, big->out + i++, 1);
		while (i++ < big->idx_pnt + fmt->prec)
			fmt->rtn += write(1, "0", 1);
	}
}

int				ft_print_floating(t_fmt *fmt)
{
	t_dbl		dbl;
	t_big		big;
	t_blk		blk;

	dbl.val = va_arg(fmt->ap, double);
	ft_bzero(&big, sizeof(big));
	big.expo = dbl.s_dbl.expo - 1023;
	// (추후 구현) 수렴, 발산 판단
	ft_get_52_bit(dbl.s_dbl.mtsa, &big);
	ft_get_integer(&big);
	ft_get_fraction(&big);
	// feg 판단
	ft_get_output(&big, big.len_i, big.len_f);
	ft_round_up(&big, fmt, 0, 0);
	ft_bzero(&blk, sizeof(blk));
	ft_decide_block_nbr(&big, fmt, &blk, dbl.s_dbl.sign);
	ft_decide_block_floating(fmt, &blk);
	ft_write_floating(&big, fmt, &blk);
	// 할당 해제.
	return (0);
}
