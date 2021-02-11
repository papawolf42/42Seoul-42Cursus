/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:48:08 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/11 15:45:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <time.h>

# define ERROR -1
# define CHARSET_DECI "0123456789"
# define CHARSET_OCTA "01234567"
# define CHARSET_HEXA_L "0123456789abcdef"
# define CHARSET_HEXA_U "0123456789ABCDEF"
# define CHARSET_NULL "(null)"

/*
** typedef
*/

typedef long long int			t_llint;
typedef long int				t_lint;
typedef short int				t_sint;
typedef int						t_int;
typedef	char					t_char;

typedef unsigned long long int	t_ullint;
typedef unsigned long int		t_ulint;
typedef unsigned short int		t_usint;
typedef unsigned int			t_uint;
typedef	unsigned char			t_uchar;

/*
**  '-' : left-justify
**  '+' : Forces to preceed the result with a plus or minus sign
**  ' ' : a blank space is inserted before the value.
**  '#' : Used with o, x or X specifiers the value is preceeded with
**        0, 0x or 0X respectively for values different than zero.
**        ex) 42 = 032 = 0x2a
**        Used with a, A, e, E, f, F, g or G it forces the written output
**        to contain a decimal point even if no more digits follow.
**  '0' : Left-pads the number with zeroes (0) instead of spaces
**  '*' : as an additional integer value argument preceding the argument
**        that has to be formatted.
*/

typedef enum	e_flg
{
	minus,
	plus,
	space,
	hash,
	zero,
	star,
	dot
}				t_flg;

typedef enum	e_len
{
	l,
	ll,
	h,
	hh
}				t_len;

typedef struct	s_fmt
{
	const char	*str;
	va_list		ap;
	char		flag[7];
	int			wid;
	int			prec;
	char		len;
	int			size;
	char		spec;
	t_llint		nbr;
	t_ullint	unbr;
	int			base;
	char		*cbase;
	int			rtn;
}				t_fmt;

/*
** (left pad)(pre : prefix or sign or space)(zero)(precision)(number)(right pad)
**                         (round : 1)(integer)(point)(fraction)(more precision)
*/

typedef struct	s_blk
{
	char		buff[33];
	int			pad;
	int			rpad;
	int			nbr;
	int			prec;
	int			zero;
	int			space;
	int			minus;
	int			plus;
	int			prefix;
	int			pre;
	int			lpad;
}				t_blk;

/*
** sturct for floating point
*/

typedef union	u_dbl
{
	double		val;
	struct
	{
		size_t	mtsa : 52;
		size_t	expo : 11;
		size_t	sign : 1;
	}			s_dbl;
}				t_dbl;

typedef struct	s_big
{
	char		is_zero;
	char		is_g;
	char		mtsa[54];
	int			expo;
	char		intg[309];
	char		frac[1077];
	char		out[1385];
	int			len_i;
	int			len_f;
	int			idx_pnt;
	int			idx_nul;
	int			idx_g;
	char		out_e[6];
	int			idx_pnt_e;
	int			int_e;
	int			len_e;
}				t_big;

/*
** ft_printf.c
*/

void			ft_reset_fmt(t_fmt *fmt);
void			ft_initialize_fmt(t_fmt *fmt, const char *format);
void			ft_info_fmt(t_fmt *fmt);
int				ft_print_iterative(t_fmt *fmt);
int				ft_printf(const char *format, ...);

/*
** ft_iterative
*/

int				ft_print_nonformat(t_fmt *fmt);
int				ft_parse_format(t_fmt *fmt);
int				ft_print_format(t_fmt *fmt);

/*
** ft_parce2.c
*/

int				ft_parse_nbr_nonestar(t_fmt *fmt, t_flg flg);
int				ft_atoi_nonstar(t_fmt *fmt);
int				ft_parse_nbr(t_fmt *fmt, t_flg flg);

/*
** ft_parce.c
*/

int				ft_parse_flag(t_fmt *fmt);
int				ft_parse_prec(t_fmt *fmt);
int				ft_parse_len(t_fmt *fmt);
int				ft_parse_spec(t_fmt *fmt);

/*
** ft_print_integer.c
*/

void			ft_len_signed(t_fmt *fmt);
void			ft_len_unsigned(t_fmt *fmt);
int				ft_decide_block(t_fmt *fmt, t_blk *blk);
int				ft_write_integer(t_fmt *fmt, t_blk *blk);
int				ft_print_integer(t_fmt *fmt);

/*
** ft_print_integer2.c
*/

int				ft_base_unsigned(t_fmt *fmt);
int				ft_count_digit(t_ullint nbr, t_ullint base);
void			ft_itoa_signed(t_fmt *fmt, t_blk *blk);
void			ft_itoa_unsigned(t_fmt *fmt, t_blk *blk);

/*
** ft_print_letter.c
*/

void			ft_print_character_uni(t_fmt *fmt, char *wc, int *len);
int				ft_print_character(t_fmt *fmt, int len);
int				ft_print_string(t_fmt *fmt, char *s);
int				ft_print_letter(t_fmt *fmt);

/*
** ft_print_unicode.c
*/

int				ft_encoding_utf8(char *utf8, wchar_t s);
int				ft_print_uni(t_fmt *fmt, wchar_t **s, t_uint *len);
int				ft_print_string_uni(t_fmt *fmt, wchar_t *s, int lpad, int rpad);

/*
** ft_print_floating.c
*/

int				ft_is_inf_or_nan(t_fmt *fmt, t_dbl *dbl, t_big *big, int expo);
void			ft_get_52_bit(t_dbl *dbl, t_big *big);
int				ft_print_f(t_fmt *fmt, t_dbl *dbl, t_big *big, t_blk *blk);
int				ft_print_e(t_fmt *fmt, t_dbl *dbl, t_big *big, t_blk *blk);
int				ft_print_floating(t_fmt *fmt);

/*
** ft_print_floating_bigint.c
*/

int				ft_make_intg_dp(char intg_dp[][309], int max, int expo);
void			ft_sum_intg_dp(t_big *big, char intg_dp[][309],
								int limit, int toggle);
int				ft_make_frac_dp(char frac_dp[][1077], int max, int expo);
void			ft_sum_frac_dp(t_big *big, char frac_dp[][1077],
								int limit, int toggle);
void			ft_get_decimal_from_52bit(t_big *big);

/*
** ft_print_floating_common.c
*/

int				ft_zerolen(char *str);
void			ft_get_output(t_big *big, int len_i, int len_f);
void			ft_redirect_to_fe(t_fmt *fmt, t_big *big);
int				ft_decide_block_floating(t_fmt *fmt, t_blk *blk);
void			ft_write_floating(t_big *big, t_fmt *fmt, t_blk *blk);

/*
** ft_print__floating_f.c
*/

void			ft_round_up_f(t_big *big, t_fmt *fmt, int up, int head);
void			ft_trailing_zero_f(t_big *big, t_fmt *fmt);
void			ft_decide_block_f(t_fmt *fmt, t_big *big, t_blk *blk,
									int sign);
void			ft_write_f(t_big *big, t_fmt *fmt);

/*
** ft_print_floating_e.c
*/

int				ft_rount_up_e(t_big *big, t_fmt *fmt, int up, int head);
void			ft_trailing_zero_e(t_big *big, t_fmt *fmt);
void			ft_get_output_e(t_big *big);
void			ft_decide_block_e(t_fmt *fmt, t_big *big, t_blk *blk, int sign);
void			ft_write_e(t_big *big, t_fmt *fmt);

/*
** ft_print_etc.c
*/

int				ft_print_address(t_fmt *fmt);
int				ft_print_count(t_fmt *fmt);
int				ft_print_percent(t_fmt *fmt);
int				ft_print_etc(t_fmt *fmt);

/*
** ft_utils.c
*/

int				ft_abs(int nbr);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

#endif
