/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:11:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/06 20:15:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_encoding_utf8(wchar_t lc, char *wc)
{
	int			len;

	if (lc < 0x000080 && (len = 1))
		wc[0] = lc;
	else if (lc < 0x000800 && (len = 2))
	{
		wc[0] = 0b11000000 | (lc >> 0x06);
		wc[1] = 0b10000000 | (lc >> 0x00 & 0b00111111);
	}
	else if (lc < 0x010000 && (len = 3))
	{
		wc[0] = 0b11100000 | (lc >> 0x0c);
		wc[1] = 0b10000000 | (lc >> 0x06 & 0b00111111);
		wc[2] = 0b10000000 | (lc >> 0x00 & 0b00111111);
	}
	else if (lc < 0x200000 && (len = 4))
	{
		wc[0] = 0b11110000 | (lc >> 0x12);
		wc[1] = 0b10000000 | (lc >> 0x0c & 0b00111111);
		wc[2] = 0b10000000 | (lc >> 0x06 & 0b00111111);
		wc[3] = 0b10000000 | (lc >> 0x00 & 0b00111111);
	}
	return (len);
}

void		ft_print_character_unicode(t_fmt *fmt, char *wc, int *len)
{
	wchar_t		lc;
	
	lc = va_arg(fmt->ap, wchar_t);
	ft_bzero(wc, 5);
	*len = ft_encoding_utf8(lc, wc);
}


int			ft_print_character(t_fmt *fmt)
{
	char	c;
	char	wc[5];
	int		len;
	int		lpad;
	int		rpad;

	if (fmt->len == 'l')
		ft_print_character_unicode(fmt, wc, &len);
	else if ((len = 1))
		c = (char)va_arg(fmt->ap, int);
	fmt->size = ft_max(1, fmt->wid);
	lpad = !fmt->flag[minus] ? fmt->size - len : 0;
	rpad = fmt->flag[minus] ? fmt->size - len : 0;
	while (lpad--)
		fmt->rtn += write(1, " ", 1);
	fmt->rtn += fmt->len == 'l' ? write(1, &wc, len) : write(1, &c, 1);
	while (rpad--)
		fmt->rtn += write(1, " ", 1);
	return (0);
}

int			ft_print_string(t_fmt *fmt, char *s)
{
	int		len;
	int		lpad;
	int		zpad;
	int		rpad;

	if (s == NULL)
		s = CHARSET_NULL;
	len = fmt->flag[dot] ? ft_min(ft_strlen(s), fmt->prec) : ft_strlen(s);
	fmt->size = ft_max(len, fmt->wid);
	lpad = !fmt->flag[minus] && !fmt->flag[zero] ? fmt->size - len : 0;
	zpad = !fmt->flag[minus] && fmt->flag[zero] ? fmt->size - len : 0;
	rpad = fmt->flag[minus] ? fmt->size - len : 0;
	while (lpad--)
		fmt->rtn += write(1, " ", 1);
	while (zpad--)
		fmt->rtn += write(1, "0", 1);
	fmt->rtn += write(1, s, len);
	while (rpad--)
		fmt->rtn += write(1, " ", 1);
	return (0);
}

int			ft_print_letter(t_fmt *fmt)
{
	if (fmt->spec == 'c')
		if (ft_print_character(fmt) == ERROR)
			return (ERROR);
	if (fmt->spec == 's')
		if (ft_print_string(fmt, va_arg(fmt->ap, char *)) == ERROR)
			return (ERROR);
	return (0);
}
