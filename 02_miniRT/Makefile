# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 16:42:32 by gunkim            #+#    #+#              #
#    Updated: 2021/04/29 21:46:27 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	miniRT - Makefile
#	----------------------------------------
#	Refer to : https://github.com/google/honggfuzz/blob/master/Makefile
#	Refer to : https://github.com/JaeSeoKim/42cursus/blob/master/01_ft_printf/Makefile

# =========================
# what we want to make
# =========================

NAME    := miniRT

# =========================
# library path
# =========================

DIR_MLX             := lib/minilibx_mms_20200219
DIR_LIBFT           := lib/libft
DIR_GET_NEXT_LINE   := lib/get_next_line

LIB_MLX             := libmlx.dylib
LIB_LIBFT           := libft.a
LIB_GET_NEXT_LINE   := libgnl.a

NAME_MLX            := $(DIR_MLX)/$(LIB_MLX)
NAME_LIBFT          := $(DIR_LIBFT)/$(LIB_LIBFT)
NAME_GET_NEXT_LINE  := $(DIR_GET_NEXT_LINE)/$(LIB_GET_NEXT_LINE)

# =========================
# implicit rule
# =========================

CC        := gcc
CFLAGS    := -g
CFLAGS    += -Wall
CFLAGS    += -Wextra
CFLAGS    += -Werror

INCLUDES  := -I $(DIR_MLX) \
			 -I $(DIR_LIBFT)/include \
			 -I $(DIR_GET_NEXT_LINE) \
			 -I include
LIBFLAGS  := -L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit \
			 -L $(DIR_LIBFT) -lft \
			 -L $(DIR_GET_NEXT_LINE) -lgnl

RM        := rm
RFLAGS    := -rf

# =========================
# path
# =========================

DIR_INC := include
DIR_OBJ := obj
DIR_SRC := src

# =========================
# source files
# =========================

DIR_SRC_COLOR := color
SRCS_COLOR := $(addprefix $(DIR_SRC_COLOR)/, \
	ft_rgb_to_data.c \
)

DIR_SRC_OBJECT := object
SRCS_OBJECT := $(addprefix $(DIR_SRC_OBJECT)/, \
	camera.c \
	light.c \
	object.c \
	sphere.c \
)

DIR_SRC_PARSE := parse
SRCS_PARSE := $(addprefix $(DIR_SRC_PARSE)/, \
	parse.c \
)

DIR_SRC_UTILS := utils
SRCS_UTILS := $(addprefix $(DIR_SRC_UTILS)/, \
	utils_str.c \
)

DIR_SRC_VECTOR := vector
SRCS_VECTOR := $(addprefix $(DIR_SRC_VECTOR)/, \
	ft_vec3_geometry.c \
	ft_vec3_length.c \
	ft_vec3_multiplication.c \
	ft_vec3_plus_minus.c \
	ft_vec3_set.c \
)

SRCS := $(addprefix $(DIR_SRC)/, \
	minirt.c \
	$(SRCS_COLOR) \
	$(SRCS_OBJECT) \
	$(SRCS_PARSE) \
	$(SRCS_UTILS) \
	$(SRCS_VECTOR) \
)

# =========================
# vpath
# =========================

vpath %.c \
	$(DIR_SRC) \
	$(DIR_SRC)/$(DIR_SRC_COLOR) \
	$(DIR_SRC)/$(DIR_SRC_OBJECT) \
	$(DIR_SRC)/$(DIR_SRC_UTILS) \
	$(DIR_SRC)/$(DIR_SRC_PARSE) \
	$(DIR_SRC)/$(DIR_SRC_VECTOR)

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

.PHONY: all clean fclean re

all : $(NAME)

bonus : $(NAME)

clean :
	@$(MAKE) clean -C $(DIR_MLX)
	@$(MAKE) clean -C $(DIR_LIBFT)
	@$(MAKE) clean -C $(DIR_GET_NEXT_LINE)
	@$(RM) $(RFLAGS) $(OJBS)

fclean :
	@$(MAKE) clean -C $(DIR_MLX)
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@$(MAKE) fclean -C $(DIR_GET_NEXT_LINE)
	@$(RM) $(RFLAGS) $(NAME)
	@printf "[$(NAME)] ✔️  Cleaned all !!$(LF)"

re : fclean all

.PHONY: depend clean_depend

depend : $(DEPS)

clean_depend :
	@$(RFLAGS) depend_file
	@printf "[$(NAME)] 🧹 Cleaned dependency files$(LF)"

%.d : %.c
	@$(CC) $(INCLUDES) -MM $< | sed 's|^|$(DIR_OBJ)/|' | sed 's|$(DIR_OBJ)/  ||' >> depend_file

$(NAME) : $(DIR_OBJ) $(NAME_MLX) $(NAME_LIBFT) $(NAME_GET_NEXT_LINE) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS) -o $(NAME)
	@install_name_tool -change $(LIB_MLX) $(DIR_MLX)/$(LIB_MLX) $(NAME)
	@printf "$(ERCR)[$(NAME)] ✔️  Make complete !!"

$(DIR_OBJ) :
	@mkdir -p $(DIR_OBJ)
	@printf "[$(NAME)] 📁 Created directory $(DIR_OBJ)$(LF)"

$(DIR_OBJ)/%.o : %.c
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@ -I $(DIR_INC)
	@printf "$(ERCR)[$(NAME)] 🔧 Compiling object file $@"

$(NAME_MLX) :
	@printf "$(ERCR)[$(LIB_MLX)] 🔧 Compiling mlx library, Please wait..."
	@$(MAKE) all -C $(DIR_MLX)
	@printf "$(ERCR)[$(LIB_MLX)] ✔️  Compiled done$(LF)"

$(NAME_LIBFT) :
	@$(MAKE) -s all -C $(DIR_LIBFT)

$(NAME_GET_NEXT_LINE) :
	@$(MAKE) -s all -C $(DIR_GET_NEXT_LINE)

# DO NOT DELETE

obj/minirt.o: src/minirt.c include/minirt.h lib/minilibx_mms_20200219/mlx.h \
lib/libft/include/libft.h include/struct.h include/ray.h \
include/vector.h include/alias.h include/color.h
obj/ft_rgb_to_data.o: src/color/ft_rgb_to_data.c include/color.h \
include/vector.h include/ray.h
obj/camera.o: src/object/camera.c lib/libft/include/libft.h include/struct.h \
include/ray.h include/vector.h include/alias.h include/color.h
obj/light.o: src/object/light.c lib/libft/include/libft.h include/struct.h \
include/ray.h include/vector.h include/alias.h include/color.h
obj/object.o: src/object/object.c lib/libft/include/libft.h include/struct.h \
include/ray.h include/vector.h include/alias.h include/color.h
obj/sphere.o: src/object/sphere.c include/struct.h include/ray.h \
include/vector.h include/alias.h include/color.h
obj/parse.o: src/parse/parse.c lib/libft/include/libft.h include/struct.h \
include/ray.h include/vector.h include/alias.h include/color.h
obj/utils_str.o: src/utils/utils_str.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/ray.h include/vector.h include/alias.h \
include/color.h
obj/ft_vec3_length.o: src/vector/ft_vec3_length.c include/vector.h
obj/ft_vec3_multiplication.o: src/vector/ft_vec3_multiplication.c \
include/vector.h
obj/ft_vec3_plus_minus.o: src/vector/ft_vec3_plus_minus.c include/vector.h
obj/ft_vec3_set.o: src/vector/ft_vec3_set.c include/vector.h include/alias.h
