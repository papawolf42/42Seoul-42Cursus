# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 01:26:55 by gunkim            #+#    #+#              #
#    Updated: 2020/12/09 14:39:30 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# What really want to make

LIB_PRINTF := libftprintf.a
LIB_LIBFT := libft.a

# Directory

DIR_PRINTF := ft_printf
DIR_LIBFT := libft

# implicit Rules

AR := ar
ARFLAGS := -rcu

RM := rm -rf

$(LIB_PRINTF) : $(DIR_LIBFT)/$(LIB_LIBFT) $(DIR_PRINTF)/$(LIB_PRINTF)
	$(MAKE) -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIB_LIBFT) $(DIR_PRINTF)
	$(MAKE) -C $(DIR_PRINTF)
	cp $(DIR_PRINTF)/$(LIB_PRINTF) $(LIB_PRINTF)

.PHONY : \
	all clean fclean re \
	clean_$(DIR_LIBFT) clean_$(DIR_PRINTF) \
	fclean_$(DIR_LIBFT) fclean_$(DIR_PRINTF) \

all : $(LIB_PRINTF)

clean : clean_$(DIR_LIBFT) clean_$(DIR_PRINTF)

clean_$(DIR_LIBFT) :
	$(MAKE) -C $(DIR_LIBFT) clean

clean_$(DIR_PRINTF) :
	$(MAKE) -C $(DIR_PRINTF) clean

fclean : clean fclean_$(DIR_LIBFT) fclean_$(DIR_PRINTF)
	$(RM) $(LIB_PRINTF)

fclean_$(DIR_LIBFT) :
	$(MAKE) -C $(DIR_LIBFT) fclean

fclean_$(DIR_PRINTF) :
	$(MAKE) -C $(DIR_PRINTF) fclean

re : fclean all




