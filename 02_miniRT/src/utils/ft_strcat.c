/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:48:53 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 14:49:34 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_strcat(char *dest, char *src)
{
	char	*init_point;

	init_point = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
