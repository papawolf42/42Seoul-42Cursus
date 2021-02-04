/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:31:14 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/04 19:46:06 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_address(t_fmt *fmt)
{
	fmt->flag[hash] = 1;
	if (ft_print_integer(fmt) == ERROR)
		return (ERROR);
	return (0);
}

int			ft_print_percent(t_fmt *fmt)
{
	char	c;
	int		lpad;
	int		zpad;
	int		rpad;

	c = '%';
	fmt->size = ft_max(1, fmt->wid);
	lpad = !fmt->flag[minus] && !fmt->flag[zero] ? fmt->size - 1 : 0;
	zpad = !fmt->flag[minus] && fmt->flag[zero] ? fmt->size - 1 : 0;
	rpad = fmt->flag[minus] ? fmt->size - 1 : 0;
	while (lpad--)
		fmt->rtn += write(1, " ", 1);
	while (zpad--)
		fmt->rtn += write(1, "0", 1);
	fmt->rtn += write(1, &c, 1);
	while (rpad--)
		fmt->rtn += write(1, " ", 1);
	return (0);
}