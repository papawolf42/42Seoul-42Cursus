/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floating_bigint.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:27:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 12:03:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void			ft_get_decimal_from_52bit(t_big *big)
{
	static int	intg_max;
	static char	intg_dp[1024][309] = {"1", };
	static int	frac_max;
	static char	frac_dp[1075][1077] = {"5", };

	if (intg_max < big->expo)
		intg_max = ft_make_intg_dp(intg_dp, intg_max, big->expo);
	ft_sum_intg_dp(big, intg_dp, 0, 0);
	if (frac_max < -1 * big->expo + 51)
		frac_max = ft_make_frac_dp(frac_dp, frac_max, -1 * big->expo + 51);
	ft_sum_frac_dp(big, frac_dp, big->expo, -1);
}
