/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:06:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "alias.h"

int			ft_is_endstr(char *big, char *little)
{
	char	*endstr;

	endstr = ft_strnstr(big, little, ft_strlen(big));
	if (endstr != NULL)
	{
		endstr += ft_strlen(endstr);
		if (*endstr == '\0')
		{
			return (success);
		}
	}
	return (fail);
}
