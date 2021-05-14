/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:07:39 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/14 21:22:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_2ND_ARG_NOT_END_RT "scene file must end with .rt"
# define ERR_3RD_ARG_WRONG "2nd argument can be --save"
# define ERR_WRONG_NUMBERS_ARG "Wrong argument, 1st argument is .rt file path, 2nd argument can be '--save' option to save image as bmp file"

void		ft_error_message(char *err_msg);

#endif