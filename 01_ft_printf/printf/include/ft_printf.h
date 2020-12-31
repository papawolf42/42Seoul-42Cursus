/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:48:08 by gunkim            #+#    #+#             */
/*   Updated: 2020/12/06 17:51:11 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>


# define ERROR -1

typedef enum
{
	minus,
	plus,
	space,
	pound,
	zero
}					t_flg;

typedef enum
{
	l,
	ll,
	h,
	hh
}					t_len;

typedef struct		s_fmt
{
	char			*str;
	va_list			ap;
	char			flag[6];
	int				wid;
	int				prec;
	int				len;
	char			spec;
	char			buff[21];
	int				rtn;
}					t_fmt;

#endif
