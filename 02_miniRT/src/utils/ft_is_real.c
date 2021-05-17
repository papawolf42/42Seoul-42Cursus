/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_real.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:29:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/18 01:44:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"

static t_bool	ft_is_real_exception(char *s)
{
	t_bool	sign;

	sign = false;
	if (*s == '.')
		return (fail);
	if (*s == '-' || *s == '+')
	{
		sign = true;
		s++;
	}
	if (sign == true && *s == '.')
		return (fail);
	return (success);
}

t_bool			ft_is_real(char *s)
{
	if (ft_is_real_exception(s))
		return (fail);
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
	if (*s != '\0')
		return (fail);
	return (success);
}
