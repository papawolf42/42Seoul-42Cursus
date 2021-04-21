/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:06:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/04/21 23:24:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_is_endstr(char *big, char *little)
{
	char	*endstr;

	endstr = ft_strnstr(big, little, ft_strlen(big));
	if (endstr != NULL)
	{
		endstr += ft_strlen(endstr);
		if (*endstr == '\0')
		{
			return (1);
		}
	}
	return (0);
}