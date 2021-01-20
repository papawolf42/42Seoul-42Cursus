# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 01:26:55 by gunkim            #+#    #+#              #
#    Updated: 2021/01/19 22:36:54 by gunkim           ###   ########.fr        #
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

#SRCS := $(wildcard $(DIR_SRC)/*.c)

SRCS := $(addprefix $(DIR_SRC)/, \
	ft_printf.c \
	iterative.c \
	parse.c \
	print_id.c \
	print_u.c \
	print_o.c \
	print_integer.c \
	spec_s.c \
	utils.c \
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

obj/ft_printf.o: src/ft_printf.c include/printf.h ../libft/include/libft.h
obj/iterative.o: src/iterative.c include/printf.h ../libft/include/libft.h
obj/parse.o: src/parse.c include/printf.h ../libft/include/libft.h
obj/print_id.o: src/print_id.c include/printf.h ../libft/include/libft.h
obj/print_u.o: src/print_u.c include/printf.h ../libft/include/libft.h
obj/print_o.o: src/print_o.c include/printf.h ../libft/include/libft.h
obj/print_integer.o: src/print_integer.c include/printf.h ../libft/include/libft.h
obj/spec_s.o: src/spec_s.c include/printf.h ../libft/include/libft.h
obj/utils.o: src/utils.c include/printf.h ../libft/include/libft.h
