/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:07:29 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 10:54:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_strnchr(char *s, char c, size_t len)
{
	while (len--)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static char		**ft_get_str(char **strs, const char *s, char *c)
{
	size_t		num;
	size_t		clen;
	const char	*start;

	num = 0;
	clen = ft_strlen(c);
	while (*s)
	{
		while (ft_strnchr(c, *s, clen) && *s)
			s++;
		if (*s == '\0')
			break ;
		if (!ft_strnchr(c, *s, clen))
			start = s;
		while (!ft_strnchr(c, *s, clen) && *s)
			s++;
		strs[num] = (char *)malloc(sizeof(char) * (s - start + 1));
		if (!strs[num])
			return (NULL);
		ft_strlcpy(strs[num], start, s - start + 1);
		num++;
	}
	return (strs);
}

static char		**ft_get_strs(char const *s, char *c)
{
	size_t	num;
	size_t	clen;
	char	**strs;

	num = 0;
	clen = ft_strlen(c);
	while (*s)
	{
		while (ft_strnchr(c, *s, clen) && *s)
			s++;
		if (!ft_strnchr(c, *s, clen) && *s)
			num++;
		while (!ft_strnchr(c, *s, clen) && *s)
			s++;
	}
	if (*c == '\0')
		num++;
	strs = (char **)ft_calloc((num + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	return (strs);
}

static void		ft_free_all(char **strs)
{
	while (*strs)
	{
		free(*strs);
		(*strs)++;
	}
	free(strs);
}

char			**ft_split_rt(char *s, char *c)
{
	char	**strs;

	if (!s)
		return (NULL);
	if (!(strs = ft_get_strs(s, c)))
		return (NULL);
	if (!(ft_get_str(strs, s, c)))
	{
		ft_free_all(strs);
		return (NULL);
	}
	return (strs);
}
