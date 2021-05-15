/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:58:33 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/15 15:21:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"

t_bool			ft_is_integer(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) == false)
			return (false);
		s++;
	}
	return (true);
}
