/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_real.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:25:37 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/16 17:52:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "error.h"
#include "utils.h"

t_bool		ft_parse_real(double *dst, char *src)
{
	if (ft_is_real(src))
		return (fail);
	*dst = ft_atof(src);
	return (success);
}
