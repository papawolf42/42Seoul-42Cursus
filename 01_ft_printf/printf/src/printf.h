/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:48:08 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/13 15:39:11 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define ERROR -1

/*
** typedef
*/

typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;
typedef long int				t_lint;
typedef unsigned long int		t_ulint;
typedef short int				t_sint;
typedef unsigned short int		t_usint;

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
	minus, // 0
	plus,  // 1
	space, // 2
	hash,  // 3
	zero,  // 4
	star,  // 5
	dot    // 6
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
	const char	*str;
	va_list		ap;
	char		flag[7];
	int			wid;
	int			prec;
	int			len;
	int			size;
	char		spec;
	char		buff[21];
	char		*out;
	int			rtn;
}				t_fmt;

/*
** (left padding)(pre : prefix or sign or space)(precision)(number)(right padding)
*/

typedef struct	s_blk
{
	char		buff[33];
	int			rpad;
	int			nbr;
	int			prec;
	int			space;
	int			minus;
	int			plus;
	int			prefix;// must implement later
	int			pre;
	int			lpad;
}				t_blk;

/*
** printf.c
*/

void			ft_reset_fmt(t_fmt *fmt);
void			ft_initialize_fmt(t_fmt *fmt, const char *format);
void			ft_info_fmt(t_fmt *fmt);
int				ft_print_iterative(t_fmt *fmt);
int				ft_printf(const char *format, ...);
int				main(void);

/*
** iterative
*/

int				ft_print_nonformat(t_fmt *fmt);
int				ft_parse_format(t_fmt *fmt);
int				ft_print_format(t_fmt *fmt);

/*
** parce.c
*/

int				ft_parse_nbr_nonestar(t_fmt *fmt, t_flg flg);
int				ft_atoi_parse_star(t_fmt *fmt);

int				ft_parse_nbr(t_fmt *fmt, t_flg flg);
int				ft_parse_flag(t_fmt *fmt);
int				ft_parse_prec(t_fmt *fmt);
int				ft_parse_len(t_fmt *fmt);
int				ft_parse_spec(t_fmt *fmt);

/*
** parce2.c
*/

/*
** print.c
*/

int				ft_print_format(t_fmt *fmt);

/*
** ft_print_integer.c
*/

int				ft_itoa_costom(t_fmt *fmt, t_blk *blk);
int				ft_get_out(t_fmt *fmt, t_blk *blk);
int				ft_get_index(t_fmt *fmt, t_blk *blk);
int				ft_print_decimal(t_fmt *fmt, t_blk *blk);
int				ft_print_integer(t_fmt *fmt);

/*
** utils.c
*/

int				ft_count_digit(t_llint nbr);
int				ft_abs(int nbr);
int				ft_max(int a, int b);

/*
** spec_s.c
*/

int				ft_print_s(t_fmt *fmt);


#endif
