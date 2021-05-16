/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:02:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 18:04:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "error.h"
#include "utils.h"

t_bool		ft_parse_integer(int *dst, char *src)
{
	if (ft_is_integer(src))
		return (fail);
	*dst = ft_atoi(src);
	return (success);
}

t_bool		ft_parse_color_integer(double *dst, char *src)
{
	if (ft_is_integer(src))
		return (fail);
	*dst = (double)ft_atoi(src) / 255.0;
	return (success);
}
