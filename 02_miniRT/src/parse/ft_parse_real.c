/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_real.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:25:37 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 12:16:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias.h"
#include "error.h"
#include "utils.h"

t_bool		ft_parse_real(double *dst, char *src)
{
	if (ft_is_real(src))
		return (ft_err_msg(ERR_BAD_REAL));
	*dst = ft_atof(src);
	return (success);
}
