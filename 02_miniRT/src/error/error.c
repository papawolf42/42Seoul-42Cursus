/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:05:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/14 21:24:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "error.h"
#include "libft.h"

void		ft_error_message(char *err_msg)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n  ", 1);
	ft_putstr_fd(err_msg, 1);
	ft_putchar_fd('\n', 1);
	// return (false);
}

