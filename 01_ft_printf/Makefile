# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 01:26:55 by gunkim            #+#    #+#              #
#    Updated: 2021/01/09 17:00:44 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	libft.a - Makefile
#	----------------------------------------
#	Refer to : https://github.com/google/honggfuzz/blob/master/Makefile
#	Refer to : https://github.com/JaeSeoKim/42cursus/blob/master/01_ft_printf/Makefile

# =========================
# what we want to make
# =========================

NAME        := libftprintf.a
#
# =========================
# implicit rule
# =========================

CC      := gcc
CFLAGS  :=
CFLAGS  += -Wall
CFLAGS  += -Wextra
#CFLAGS  += -Werror

AR      := ar
ARFLAGS := -rcs

RM      := rm
RFLAGS  := -rf

# =========================
# path
# =========================

DIR_LIBFT   := libft
DIR_PRINTF  := ft_printf

LIB_LIBFT   := libft.a
LIB_PRINTF  := printf.a

NAME_LIBFT  := $(DIR_LIBFT)/$(LIB_LIBFT)
NAME_PRINTF := $(DIR_PRINTF)/$(LIB_PRINTF)

# =========================
# ANSI/VT100
# =========================

LF      := \n
CR      := \r
ESC     := \e

ER      := $(ESC)[1K
CRLF    := $(CR)$(LF)
ERCR    := $(ER)$(CR)

# =========================
# rules
# =========================

.PHONY: all clean fclean re

all : $(NAME)

clean :
	@$(MAKE) clean -C $(DIR_LIBFT)
	@$(MAKE) clean -C $(DIR_PRINTF)
	@$(RM) $(RFLAGS) *.o

fclean :
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@$(MAKE) fclean -C $(DIR_PRINTF)
	@$(RM) $(RFLAGS) $(NAME) $(LIB_LIBFT) $(LIB_PRINTF)
	@$(RM) $(RFLAGS) $(NAME) $(LIB_LIBFT) $(LIB_PRINTF)
	@$(RM) $(RFLAGS) *.o __.SYMDEF\ SORTED $(LIB_LIBFT) $(LIB_PRINTF)
	@printf "[$(NAME)] ✔️  Cleaned all !!\n"

re : fclean all

$(NAME) : $(NAME_LIBFT) $(NAME_PRINTF)
	@cp $(NAME_LIBFT) $(LIB_LIBFT) && $(AR) -x $(LIB_LIBFT)
	@cp $(NAME_PRINTF) $(LIB_PRINTF) && $(AR) -x $(LIB_PRINTF)
	@$(AR) $(ARFLAGS) $(NAME) *.o
	@$(RM) $(RFLAGS) *.o __.SYMDEF\ SORTED $(LIB_LIBFT) $(LIB_PRINTF)
	@printf "[$(NAME)] ✔️  Make complete !!\n"

.PHONY : test

TEST = test

$(TEST) :
	@$(MAKE) -s all -C $(DIR_LIBFT)
	@$(MAKE) -s all -C $(DIR_PRINTF)
	@cp $(NAME_LIBFT) $(LIB_LIBFT) && $(AR) -x $(LIB_LIBFT)
	@cp $(NAME_PRINTF) $(LIB_PRINTF) && $(AR) -x $(LIB_PRINTF)
	@$(CC) -g $(CFLAGS) $(DIR_LIBFT)/obj/*.o $(DIR_PRINTF)/obj/*.o main.c -o $(TEST) -I $(DIR_PRINTF)/include -I$(DIR_LIBFT)/include
	@$(AR) $(ARFLAGS) $(NAME) *.o
	@$(RM) $(RFLAGS) *.o __.SYMDEF\ SORTED $(LIB_LIBFT) $(LIB_PRINTF)
	@printf "[$(NAME)] ✔️  Make complete !!\n"

$(NAME_LIBFT) :
	@$(MAKE) -s all -C $(DIR_LIBFT)

$(NAME_PRINTF) :
	@$(MAKE) -s all -C $(DIR_PRINTF)
