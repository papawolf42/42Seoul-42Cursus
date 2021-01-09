/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:36:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/09 21:20:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_nonformat(t_fmt *fmt)
{
	while (*fmt->str != '\0' && *fmt->str != '%')
	{
		fmt->rtn += write(1, fmt->str, 1);
		fmt->str++;
	}
	return (0);
}

int		ft_parse_format(t_fmt *fmt)
{
	if (*fmt->str != '%' || *fmt->str == '\0')
		return (0);
	ft_parse_flag(fmt);
//	ft_parse_wid(fmt);
//	ft_parse_prec(fmt);
//	ft_parse_len(fmt);
//	ft_parse_spec(fmt);
	return (0);
}

/*
int		ft_print_process(t_fmt *fmt)
{
	//if (fmt->spec == 's')
		//ft_print_s(fmt);
	return (0);
}

int		ft_print_format(t_fmt *fmt)
{
	//if (fmt->spec == 's')
		//ft_print_s(fmt);
	return (0);
}
*/
