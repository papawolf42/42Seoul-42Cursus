/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_real.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:29:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 21:53:37 by gunkim           ###   ########.fr       */
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
	if (*s != '\0')
		return (fail);
	return (success);
}