/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_real.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:29:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 18:14:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"

t_bool			ft_is_real(char *s)
{
	if (*s != '\0' && (*s == '-' || *s == '+'))
		s++;
	while (*s != '\0' && *s != '.')
	{
		if (ft_isdigit(*s) == false)
			return (fail);
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (*s != '\0' && *s != '.')
		{
			if (ft_isdigit(*s) == false)
				return (fail);
			s++;
		}
	}
	return (success);
}
