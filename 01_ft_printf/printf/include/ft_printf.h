/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:48:08 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/02 03:55:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define ERROR -1

/*
**  '-' : 좌측 정렬
**  '+' : 숫자에 대해 부호를 붙임
**  ' ' : 부호가 붙지 않는다면, 값 이전에 공백을 출력
**  '#' : o, x, X 지정자와 함께 쓰이면, 8진수 표현과 16진수 표현을 나타냄 ex) 42 = 032 = 0x2a
**        a, A, e, E, f, F, g, G 지정자와 함께 쓰이면 소수점 뒤로 값이 따라오지 않더라도,
**        출력에 소수점 출력을 강제합니다.
**        default는 소수점 이하의 수가 없다면, 소수점이 출력되지 않습니다.
**  '0' : 왼쪽 공간을 0으로 채웁니다. (너비 지정자와 함께 쓰임)
**  '*' : 너비가 지정되지 않고, 추가적인 정수의 가변인자를 받어 너비를 지정합니다.
*/

typedef enum
{
	minus,
	plus,
	space,
	hash,
	zero,
	star
}	t_flg;

typedef enum
{
	l,
	ll,
	h,
	hh
}	t_len;

typedef struct	s_fmt
{
	char		*str;
	va_list		ap;
	char		flag[6];
	int			wid;
	int			prec;
	int			len;
	char		spec;
	char		buff[21];
	int			rtn;
}				t_fmt;

#endif
