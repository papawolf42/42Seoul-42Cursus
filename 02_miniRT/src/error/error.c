/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:05:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 17:08:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "error.h"
#include "libft.h"

t_bool		ft_err_line(char *line)
{
	ft_putstr_fd(line, 1);
	ft_putchar_fd('\n', 1);
	return (fail);
}

t_bool		ft_err_msg(char *err_msg)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n  ", 1);
	ft_putstr_fd(err_msg, 1);
	ft_putchar_fd('\n', 1);
	return (fail);
}
