/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:11:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/13 11:24:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_encoding_utf8(char *utf8, wchar_t uni)
{
	int			len;

	if (uni < 0x000080 && (len = 1))
		utf8[0] = uni;
	else if (uni < 0x000800 && (len = 2))
	{
		utf8[0] = 0b11000000 | (uni >> 0x06);
		utf8[1] = 0b10000000 | (uni >> 0x00 & 0b00111111);
	}
	else if (uni < 0x010000 && (len = 3))
	{
		utf8[0] = 0b11100000 | (uni >> 0x0c);
		utf8[1] = 0b10000000 | (uni >> 0x06 & 0b00111111);
		utf8[2] = 0b10000000 | (uni >> 0x00 & 0b00111111);
	}
	else if (uni < 0x200000 && (len = 4))
	{
		utf8[0] = 0b11110000 | (uni >> 0x12);
		utf8[1] = 0b10000000 | (uni >> 0x0c & 0b00111111);
		utf8[2] = 0b10000000 | (uni >> 0x06 & 0b00111111);
		utf8[3] = 0b10000000 | (uni >> 0x00 & 0b00111111);
	}
	return (len);
}

static t_uint	ft_strlen_uni(wchar_t *s, int exist, int max)
{
	t_uint		idx;
	t_uint		len;
	t_uint		tmp;

	idx = 0;
	len = 0;
	tmp = 0;
	while (s[idx] != 0)
	{
		if (s[idx] < 0x000080)
			tmp += 1;
		else if (s[idx] < 0x000800)
			tmp += 2;
		else if (s[idx] < 0x010000)
			tmp += 3;
		else if (s[idx] < 0x200000)
			tmp += 4;
		if (!exist || (int)tmp <= max)
			len = tmp;
		idx++;
	}
	return (len);
}

int				ft_print_uni(t_fmt *fmt, wchar_t **s, t_uint *len)
{
	char		*temp;
	t_uint		idx_s;
	t_uint		idx_t;

	fmt->len = 'l';
	*len = ft_strlen_uni(*s, fmt->flag[dot], fmt->prec);
	if (!(temp = (char *)malloc(sizeof(char) * (*len + 1))))
		return (ERROR);
	idx_s = 0;
	idx_t = 0;
	while (idx_t < *len)
		idx_t += ft_encoding_utf8(temp + idx_t, *(*s + idx_s++));
	*s = (wchar_t *)temp;
	return (0);
}

int				ft_print_string_uni(t_fmt *fmt, wchar_t *s, int lpad, int rpad)
{
	t_uint		len;
	int			zpad;

	if (s == NULL && !(fmt->len = 0))
		return (ft_print_string(fmt, NULL));
	else if (ft_print_uni(fmt, &s, &len) == ERROR)
		return (ERROR);
	len = fmt->flag[dot] ? ft_min(len, fmt->prec) : len;
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
	if (fmt->len == 'l')
		free(s);
	return (0);
}
