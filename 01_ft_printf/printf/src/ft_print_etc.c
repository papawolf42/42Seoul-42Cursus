/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:31:14 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/04 19:07:43 by gunkim           ###   ########.fr       */
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