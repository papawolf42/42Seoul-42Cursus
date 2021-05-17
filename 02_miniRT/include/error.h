/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:07:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/17 13:06:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_2ND_ARG_NOT_END_RT "Scene file must end with .rt"
# define ERR_3RD_ARG_WRONG "2nd argument can be --save"
# define ERR_WRONG_NUMBERS_ARG "Wrong argument, 1st argument is .rt file path, 2nd argument can be '--save' option to save image as bmp file"
# define ERR_GNL "Problem happens while working get_next_line"
# define ERR_PAR_NOID "Parsing liny by line, found Bad Identifier"

# define ERR_WORNG_ARG "Wrong numbers of argument"
# define ERR_WRONG_ELEMENT "Wrong Numbers of element"
# define ERR_BAD_RANGE "Bad range found"
# define ERR_BAD_INT "Bad integer found"
# define ERR_BAD_REAL "Bad real found"

# define ERR_MALLOC_FAIL "Allocating memory failed"

t_bool		ft_err_msg(char *err_msg);

#endif
