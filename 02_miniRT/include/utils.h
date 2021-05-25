/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:01:24 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 14:49:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

/*
** utils_cmp.c
*/
double			ft_max(double a, double b);
double			ft_min(double a, double b);
double			ft_saturate(double a);

/*
** utils_str.c
*/
int				ft_is_endstr(char *big, char *little);
void			ft_strcpy(char *dest, char *src);
void			ft_strcat(char *dest, char *src);

double			ft_atof(char *s);
int				ft_atoi_plus(const char *nptr);
t_bool			ft_destroy(void *something);
t_bool			ft_is_color(char *str);
t_bool			ft_is_integer(char *s);
t_bool			ft_is_real(char *s);
char			**ft_split_rt(char *s, char *c);
size_t			ft_strslen(char **strs);

#endif
