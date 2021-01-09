# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 01:26:55 by gunkim            #+#    #+#              #
#    Updated: 2021/01/09 17:54:50 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	libft.a - Makefile
#	----------------------------------------
#	Refer to : https://github.com/google/honggfuzz/blob/master/Makefile
#	Refer to : https://github.com/JaeSeoKim/42cursus/blob/master/01_ft_printf/lib/libft/Makefile

# =========================
# what we want to make
# =========================

NAME    := printf.a

# =========================
# implicit rule
# =========================

CC      := gcc
CFLAGS  :=
CFLAGS  += -Wall
CFLAGS  += -Wextra
CFLAGS  += -Werror

AR      := ar
ARFLAGS := -rcsu

RFLAGS  := rm -rf

# =========================
# path
# =========================

DIR_INC := include
DIR_OBJ := obj
DIR_SRC := src
DIR_LIBFT_INC := ../libft/include

# =========================
# source files
# =========================

SRCS := $(addprefix $(DIR_SRC)/, \
	ft_printf.c \
	parse.c \
	spec_s.c \
)

# =========================
# vpath
# =========================

vpath %.c \
	$(DIR_SRC)

# =========================
# object files
# =========================

OBJS := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

# =========================
# dependency files
# =========================

DEPS := $(SRCS:.c=.d)

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

.PHONY : all clean fclean re

all : $(NAME)

clean : clean_depend
	@$(RFLAGS) $(OBJS)
	@printf "[$(NAME)] 🧹 Cleaned object files$(LF)"

fclean : clean
	@$(RFLAGS) $(NAME)
	@printf "[$(NAME)] 🧹 Cleaned library$(LF)"

re : fclean all

.PHONY: depend clean_depend

depend : $(DEPS)

clean_depend :
	@$(RFLAGS) depend_file
	@printf "[$(NAME)] 🧹 Cleaned dependency files$(LF)"

%.d : %.c
	@$(CC) -MM $< -I$(DIR_INC) -I$(DIR_LIBFT_INC) | sed 's|^|$(DIR_OBJ)/|' >> depend_file

$(NAME) : $(DIR_OBJ) $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "$(ERCR)[$(NAME)] ✔️  Compiled done\n"

$(DIR_OBJ) :
	@mkdir -p $(DIR_OBJ)
	@printf "$(LF)[$(NAME)] 📁 Created directory $(DIR_OBJ)"

$(DIR_OBJ)/%.o : %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@ -I $(DIR_INC) -I $(DIR_LIBFT_INC)
	@printf "$(ERCR)[$(NAME)] 🔧 Compiling object file $@"
 
.SUFFIXES:

# DO NOT DELETE

obj/ft_printf.o: src/ft_printf.c include/ft_printf.h ../libft/include/libft.h
obj/parse.o: src/parse.c include/ft_printf.h ../libft/include/libft.h
obj/spec_s.o: src/spec_s.c include/ft_printf.h ../libft/include/libft.h

