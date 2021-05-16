/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:58:33 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 18:13:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"

t_bool			ft_is_integer(char *s)
{
	if (*s != '\0' && (*s == '-' || *s == '+'))
		s++;
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (fail);
		s++;
	}
	return (success);
}
