# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 16:42:32 by gunkim            #+#    #+#              #
#    Updated: 2021/05/24 22:53:24 by gunkim           ###   ########.fr        #
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
# CFLAGS    := -g3 -fsanitize=address
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
	ft_color_average.c \
	ft_rgb_to_data.c \
)

DIR_SRC_CONSOLE := console
SRCS_CONSOLE := $(addprefix $(DIR_SRC_CONSOLE)/, \
	ft_console_camera.c \
	ft_console_clear.c \
	ft_console_color.c \
	ft_console_cylinder.c \
	ft_console_light.c \
	ft_console_logo.c \
	ft_console_mode_and_object.c \
	ft_console_msg.c \
	ft_console_numberof.c \
	ft_console_plane.c \
	ft_console_real.c \
	ft_console_sphere.c \
	ft_console_square.c \
	ft_console_status.c \
	ft_console_triangle.c \
	ft_console_type.c \
	ft_console_vec.c \
)

DIR_SRC_ERROR := error
SRCS_ERROR := $(addprefix $(DIR_SRC_ERROR)/, \
	error.c \
)

DIR_SRC_EVENT := event
SRCS_EVENT := $(addprefix $(DIR_SRC_EVENT)/, \
	event_mode.c \
	event_move_x.c \
	event_move_y.c \
	event_move_z.c \
	event_resize.c \
	event_rotate_x.c \
	event_rotate_y.c \
	event_rotate_z.c \
	ft_deselect.c \
	ft_handle_key.c \
	ft_handle_mouse.c \
	ft_init_hook.c \
	ft_list_after.c \
	ft_list_before.c \
	ft_move_camera.c \
	ft_move_cylinder.c \
	ft_move_light.c \
	ft_move_object.c \
	ft_move_plane.c \
	ft_move_sphere.c \
	ft_move_square.c \
	ft_move_triangle.c \
	ft_rotate_cylinder.c \
	ft_rotate_object.c \
	ft_rotate_plane.c \
	ft_rotate_square.c \
	ft_select_object.c \
	ft_toggle_aa.c \
	ft_toggle_fe.c \
	ft_toggle_mt.c \
	ft_trigger_key.c \
	ft_trigger_mouse.c \
)

DIR_SRC_EXIT := exit
SRCS_EXIT := $(addprefix $(DIR_SRC_EXIT)/, \
	ft_destroy_mlx.c \
	ft_exit.c \
	ft_free_scene.c \
)

DIR_SRC_HIT := hit
SRCS_HIT := $(addprefix $(DIR_SRC_HIT)/, \
	ft_hit.c \
	ft_hit_cylinder.c \
	ft_hit_object.c \
	ft_hit_plane.c \
	ft_hit_sphere.c \
	ft_hit_square.c \
	ft_hit_triangle.c \
	ft_phong_color.c \
	ft_ray_at.c \
	ft_ray_determine_front.c \
	ft_ray_init_aa.c \
	ft_ray_init.c \
	ft_ray_to_color.c \
)

DIR_SRC_MATRIX := matrix
SRCS_MATRIX := $(addprefix $(DIR_SRC_MATRIX)/, \
	ft_mat_identity.c \
	ft_mat_mult_rotate.c \
	ft_mat_rotate.c \
	matrix.c \
)

DIR_SRC_MINIRT := minirt
SRCS_MINIRT := $(addprefix $(DIR_SRC_MINIRT)/, \
	ft_fill_data_aa.c \
	ft_render_aa.c \
	ft_render_mt_aa.c \
	ft_render_multi_thread.c \
	ft_render.c \
	ft_save_bmp.c \
	ft_switch.c \
	ft_write_bmp.c \
	ft_minirt.c \
)

DIR_SRC_OBJECT := object
SRCS_OBJECT := $(addprefix $(DIR_SRC_OBJECT)/, \
	ft_return_object_list.c \
	object.c \
)

DIR_SRC_PARSE := parse
SRCS_PARSE := $(addprefix $(DIR_SRC_PARSE)/, \
	ft_destroy_splits.c \
	ft_parse_ambient.c \
	ft_parse_camera.c \
	ft_parse_color.c \
	ft_parse_cylinder.c \
	ft_parse_integer.c \
	ft_parse_light.c \
	ft_parse_normal.c \
	ft_parse_plane.c \
	ft_parse_real.c \
	ft_parse_resolution.c \
	ft_parse_sphere.c \
	ft_parse_square.c \
	ft_parse_triangle.c \
	ft_parse_vector.c \
	ft_pass_line.c \
	ft_range_integer.c \
	ft_range_real.c \
	parse.c \
)

DIR_SRC_UTILS := utils
SRCS_UTILS := $(addprefix $(DIR_SRC_UTILS)/, \
	ft_atof.c \
	ft_atoi_plus.c \
	ft_destroy.c \
	ft_is_color.c \
	ft_is_integer.c \
	ft_is_real.c \
	ft_split_rt.c \
	ft_strslen.c \
	utils_cmp.c \
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
	main.c \
	$(SRCS_COLOR) \
	$(SRCS_CONSOLE) \
	$(SRCS_ERROR) \
	$(SRCS_EVENT) \
	$(SRCS_EXIT) \
	$(SRCS_HIT) \
	$(SRCS_MATRIX) \
	$(SRCS_MINIRT) \
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
	$(DIR_SRC)/$(DIR_SRC_CONSOLE) \
	$(DIR_SRC)/$(DIR_SRC_ERROR) \
	$(DIR_SRC)/$(DIR_SRC_EVENT) \
	$(DIR_SRC)/$(DIR_SRC_EXIT) \
	$(DIR_SRC)/$(DIR_SRC_HIT) \
	$(DIR_SRC)/$(DIR_SRC_MATRIX) \
	$(DIR_SRC)/$(DIR_SRC_MINIRT) \
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
	@$(RM) $(RFLAGS) depend_file
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

obj/main.o: src/main.c include/minirt.h lib/minilibx_mms_20200219/mlx.h \
lib/libft/include/libft.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/utils.h include/error.h include/parse.h include/object.h \
include/hit.h include/event.h include/exit.h
obj/ft_color_average.o: src/color/ft_color_average.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h
obj/ft_rgb_to_data.o: src/color/ft_rgb_to_data.c include/color.h \
include/vector.h include/ray.h
obj/ft_console_camera.o: src/console/ft_console_camera.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_clear.o: src/console/ft_console_clear.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_color.o: src/console/ft_console_color.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_cylinder.o: src/console/ft_console_cylinder.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h
obj/ft_console_light.o: src/console/ft_console_light.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_logo.o: src/console/ft_console_logo.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_mode_and_object.o: src/console/ft_console_mode_and_object.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h
obj/ft_console_msg.o: src/console/ft_console_msg.c lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/console.h
obj/ft_console_numberof.o: src/console/ft_console_numberof.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h
obj/ft_console_plane.o: src/console/ft_console_plane.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_real.o: src/console/ft_console_real.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_sphere.o: src/console/ft_console_sphere.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_square.o: src/console/ft_console_square.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_status.o: src/console/ft_console_status.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_triangle.o: src/console/ft_console_triangle.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h
obj/ft_console_type.o: src/console/ft_console_type.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_vec.o: src/console/ft_console_vec.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/error.o: src/error/error.c include/alias.h include/error.h \
lib/libft/include/libft.h
obj/event_mode.o: src/event/event_mode.c include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/event.h include/console.h
obj/event_move_x.o: src/event/event_move_x.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_move_y.o: src/event/event_move_y.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_move_z.o: src/event/event_move_z.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_rotate_x.o: src/event/event_rotate_x.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_rotate_y.o: src/event/event_rotate_y.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_rotate_z.o: src/event/event_rotate_z.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/ft_deselect.o: src/event/ft_deselect.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_handle_key.o: src/event/ft_handle_key.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/event.h include/exit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/console.h
obj/ft_handle_mouse.o: src/event/ft_handle_mouse.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/event.h include/exit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/console.h
obj/ft_init_hook.o: src/event/ft_init_hook.c lib/minilibx_mms_20200219/mlx.h \
include/exit.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/event.h
obj/ft_list_after.o: src/event/ft_list_after.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/console.h
obj/ft_list_before.o: src/event/ft_list_before.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/console.h
obj/ft_move_camera.o: src/event/ft_move_camera.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/object.h
obj/ft_move_cylinder.o: src/event/ft_move_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_move_light.o: src/event/ft_move_light.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/object.h
obj/ft_move_object.o: src/event/ft_move_object.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/event.h
obj/ft_move_plane.o: src/event/ft_move_plane.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_move_sphere.o: src/event/ft_move_sphere.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_move_square.o: src/event/ft_move_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_move_triangle.o: src/event/ft_move_triangle.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_rotate_cylinder.o: src/event/ft_rotate_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_rotate_object.o: src/event/ft_rotate_object.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/event.h
obj/ft_rotate_plane.o: src/event/ft_rotate_plane.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_rotate_square.o: src/event/ft_rotate_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_select_object.o: src/event/ft_select_object.c include/alias.h \
include/minirt.h lib/minilibx_mms_20200219/mlx.h \
lib/libft/include/libft.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h \
include/hit.h include/event.h
obj/ft_toggle_aa.o: src/event/ft_toggle_aa.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/console.h
obj/ft_toggle_fe.o: src/event/ft_toggle_fe.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/console.h
obj/ft_toggle_mt.o: src/event/ft_toggle_mt.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/console.h
obj/ft_trigger_key.o: src/event/ft_trigger_key.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/exit.h
obj/ft_trigger_mouse.o: src/event/ft_trigger_mouse.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/exit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/error.h
obj/ft_destroy_mlx.o: src/exit/ft_destroy_mlx.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h lib/minilibx_mms_20200219/mlx.h
obj/ft_exit.o: src/exit/ft_exit.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/exit.h
obj/ft_free_scene.o: src/exit/ft_free_scene.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_hit.o: src/hit/ft_hit.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/hit.h
obj/ft_hit_cylinder.o: src/hit/ft_hit_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_object.o: src/hit/ft_hit_object.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_plane.o: src/hit/ft_hit_plane.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/hit.h
obj/ft_hit_sphere.o: src/hit/ft_hit_sphere.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_square.o: src/hit/ft_hit_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_triangle.o: src/hit/ft_hit_triangle.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_phong_color.o: src/hit/ft_phong_color.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/utils.h include/hit.h include/phong.h
obj/ft_ray_at.o: src/hit/ft_ray_at.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_ray_determine_front.o: src/hit/ft_ray_determine_front.c \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_ray_init_aa.o: src/hit/ft_ray_init_aa.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_ray_init.o: src/hit/ft_ray_init.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_ray_to_color.o: src/hit/ft_ray_to_color.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_mat_identity.o: src/matrix/ft_mat_identity.c include/matrix.h \
include/vector.h
obj/ft_mat_mult_rotate.o: src/matrix/ft_mat_mult_rotate.c include/matrix.h \
include/vector.h
obj/ft_mat_rotate.o: src/matrix/ft_mat_rotate.c include/matrix.h \
include/vector.h
obj/matrix.o: src/matrix/matrix.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_fill_data_aa.o: src/minirt/ft_fill_data_aa.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h
obj/ft_render_aa.o: src/minirt/ft_render_aa.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/object.h include/hit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h
obj/ft_render_mt_aa.o: src/minirt/ft_render_mt_aa.c include/hit.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/error.h
obj/ft_render_multi_thread.o: src/minirt/ft_render_multi_thread.c \
include/hit.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h \
include/error.h
obj/ft_render.o: src/minirt/ft_render.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/object.h include/hit.h
obj/ft_switch.o: src/minirt/ft_switch.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_minirt.o: src/minirt/ft_minirt.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/event.h include/console.h
obj/ft_return_object_list.o: src/object/ft_return_object_list.c \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/object.o: src/object/object.c lib/libft/include/libft.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h
obj/ft_destroy_splits.o: src/parse/ft_destroy_splits.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_parse_ambient.o: src/parse/ft_parse_ambient.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h
obj/ft_parse_camera.o: src/parse/ft_parse_camera.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/parse.h include/utils.h \
include/object.h
obj/ft_parse_color.o: src/parse/ft_parse_color.c lib/libft/include/libft.h \
include/alias.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h include/error.h \
include/parse.h
obj/ft_parse_cylinder.o: src/parse/ft_parse_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_integer.o: src/parse/ft_parse_integer.c \
lib/libft/include/libft.h include/alias.h include/error.h \
include/utils.h
obj/ft_parse_light.o: src/parse/ft_parse_light.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_normal.o: src/parse/ft_parse_normal.c lib/libft/include/libft.h \
include/alias.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h include/error.h \
include/parse.h
obj/ft_parse_plane.o: src/parse/ft_parse_plane.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_real.o: src/parse/ft_parse_real.c lib/libft/include/libft.h \
include/alias.h include/error.h include/utils.h
obj/ft_parse_resolution.o: src/parse/ft_parse_resolution.c \
lib/libft/include/libft.h include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/utils.h include/error.h include/parse.h
obj/ft_parse_sphere.o: src/parse/ft_parse_sphere.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_square.o: src/parse/ft_parse_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_triangle.o: src/parse/ft_parse_triangle.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_vector.o: src/parse/ft_parse_vector.c lib/libft/include/libft.h \
include/alias.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h include/error.h \
include/parse.h
obj/ft_pass_line.o: src/parse/ft_pass_line.c include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/error.h
obj/ft_range_integer.o: src/parse/ft_range_integer.c include/alias.h
obj/ft_range_real.o: src/parse/ft_range_real.c include/alias.h
obj/parse.o: src/parse/parse.c lib/libft/include/libft.h \
lib/get_next_line/get_next_line.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/error.h include/utils.h include/parse.h include/object.h
obj/ft_atof.o: src/utils/ft_atof.c lib/libft/include/libft.h include/alias.h \
include/parse.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h
obj/ft_atoi_plus.o: src/utils/ft_atoi_plus.c
obj/ft_destroy.o: src/utils/ft_destroy.c include/alias.h
obj/ft_is_color.o: src/utils/ft_is_color.c include/alias.h include/utils.h \
include/error.h include/parse.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h
obj/ft_is_integer.o: src/utils/ft_is_integer.c lib/libft/include/libft.h \
include/alias.h
obj/ft_is_real.o: src/utils/ft_is_real.c lib/libft/include/libft.h \
include/alias.h
obj/ft_split_rt.o: src/utils/ft_split_rt.c lib/libft/include/libft.h
obj/ft_strslen.o: src/utils/ft_strslen.c
obj/utils_cmp.o: src/utils/utils_cmp.c
obj/utils_str.o: src/utils/utils_str.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_vec3_geometry.o: src/vector/ft_vec3_geometry.c include/vector.h
obj/ft_vec3_length.o: src/vector/ft_vec3_length.c include/vector.h
obj/ft_vec3_multiplication.o: src/vector/ft_vec3_multiplication.c \
include/vector.h include/error.h include/alias.h
obj/ft_vec3_plus_minus.o: src/vector/ft_vec3_plus_minus.c include/vector.h
obj/ft_vec3_set.o: src/vector/ft_vec3_set.c include/vector.h include/alias.h \
include/utils.h
obj/main.o: src/main.c include/minirt.h lib/minilibx_mms_20200219/mlx.h \
lib/libft/include/libft.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/utils.h include/error.h include/parse.h include/object.h \
include/hit.h include/event.h include/exit.h
obj/ft_color_average.o: src/color/ft_color_average.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h
obj/ft_rgb_to_data.o: src/color/ft_rgb_to_data.c include/color.h \
include/vector.h include/ray.h
obj/ft_console_camera.o: src/console/ft_console_camera.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_clear.o: src/console/ft_console_clear.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_color.o: src/console/ft_console_color.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_cylinder.o: src/console/ft_console_cylinder.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h
obj/ft_console_light.o: src/console/ft_console_light.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_logo.o: src/console/ft_console_logo.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_mode_and_object.o: src/console/ft_console_mode_and_object.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h
obj/ft_console_msg.o: src/console/ft_console_msg.c lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/console.h
obj/ft_console_numberof.o: src/console/ft_console_numberof.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h
obj/ft_console_plane.o: src/console/ft_console_plane.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_real.o: src/console/ft_console_real.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_sphere.o: src/console/ft_console_sphere.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_square.o: src/console/ft_console_square.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_status.o: src/console/ft_console_status.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_console_triangle.o: src/console/ft_console_triangle.c \
include/console.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h
obj/ft_console_type.o: src/console/ft_console_type.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h
obj/ft_console_vec.o: src/console/ft_console_vec.c include/console.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/error.o: src/error/error.c include/alias.h include/error.h \
lib/libft/include/libft.h
obj/event_mode.o: src/event/event_mode.c include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/event.h include/console.h
obj/event_move_x.o: src/event/event_move_x.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_move_y.o: src/event/event_move_y.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_move_z.o: src/event/event_move_z.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_radius.o: src/event/event_radius.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/event.h
obj/event_rotate_x.o: src/event/event_rotate_x.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_rotate_y.o: src/event/event_rotate_y.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/event_rotate_z.o: src/event/event_rotate_z.c lib/libft/include/libft.h \
include/alias.h include/event.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h
obj/ft_deselect.o: src/event/ft_deselect.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_handle_key.o: src/event/ft_handle_key.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/event.h include/exit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/console.h
obj/ft_handle_mouse.o: src/event/ft_handle_mouse.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/event.h include/exit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/console.h
obj/ft_init_hook.o: src/event/ft_init_hook.c lib/minilibx_mms_20200219/mlx.h \
include/exit.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/event.h
obj/ft_list_after.o: src/event/ft_list_after.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/console.h
obj/ft_list_before.o: src/event/ft_list_before.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/console.h
obj/ft_move_camera.o: src/event/ft_move_camera.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/object.h
obj/ft_move_cylinder.o: src/event/ft_move_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_move_light.o: src/event/ft_move_light.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/object.h
obj/ft_move_object.o: src/event/ft_move_object.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/event.h
obj/ft_move_plane.o: src/event/ft_move_plane.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_move_sphere.o: src/event/ft_move_sphere.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_move_square.o: src/event/ft_move_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_move_triangle.o: src/event/ft_move_triangle.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_rotate_cylinder.o: src/event/ft_rotate_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_rotate_object.o: src/event/ft_rotate_object.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h include/event.h
obj/ft_rotate_plane.o: src/event/ft_rotate_plane.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_rotate_square.o: src/event/ft_rotate_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/parse.h
obj/ft_select_object.o: src/event/ft_select_object.c include/alias.h \
include/minirt.h lib/minilibx_mms_20200219/mlx.h \
lib/libft/include/libft.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h include/object.h \
include/hit.h include/event.h
obj/ft_toggle_aa.o: src/event/ft_toggle_aa.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/console.h
obj/ft_toggle_fe.o: src/event/ft_toggle_fe.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/console.h
obj/ft_toggle_mt.o: src/event/ft_toggle_mt.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/console.h
obj/ft_trigger_key.o: src/event/ft_trigger_key.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/exit.h
obj/ft_trigger_mouse.o: src/event/ft_trigger_mouse.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/event.h include/exit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/error.h
obj/ft_destroy_mlx.o: src/exit/ft_destroy_mlx.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h lib/minilibx_mms_20200219/mlx.h
obj/ft_exit.o: src/exit/ft_exit.c include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/exit.h
obj/ft_free_scene.o: src/exit/ft_free_scene.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_hit.o: src/hit/ft_hit.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/hit.h
obj/ft_hit_cylinder.o: src/hit/ft_hit_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_object.o: src/hit/ft_hit_object.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_plane.o: src/hit/ft_hit_plane.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/hit.h
obj/ft_hit_sphere.o: src/hit/ft_hit_sphere.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_square.o: src/hit/ft_hit_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_hit_triangle.o: src/hit/ft_hit_triangle.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_phong_color.o: src/hit/ft_phong_color.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/utils.h include/hit.h include/phong.h
obj/ft_ray_at.o: src/hit/ft_ray_at.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_ray_determine_front.o: src/hit/ft_ray_determine_front.c \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_ray_init_aa.o: src/hit/ft_ray_init_aa.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_ray_init.o: src/hit/ft_ray_init.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_ray_to_color.o: src/hit/ft_ray_to_color.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/hit.h
obj/ft_mat_identity.o: src/matrix/ft_mat_identity.c include/matrix.h \
include/vector.h
obj/ft_mat_mult_rotate.o: src/matrix/ft_mat_mult_rotate.c include/matrix.h \
include/vector.h
obj/ft_mat_rotate.o: src/matrix/ft_mat_rotate.c include/matrix.h \
include/vector.h
obj/matrix.o: src/matrix/matrix.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h
obj/ft_fill_data_aa.o: src/minirt/ft_fill_data_aa.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h
obj/ft_render_aa.o: src/minirt/ft_render_aa.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/object.h include/hit.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h
obj/ft_render_mt_aa.o: src/minirt/ft_render_mt_aa.c include/hit.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/object.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/error.h
obj/ft_render_multi_thread.o: src/minirt/ft_render_multi_thread.c \
include/hit.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/alias.h include/color.h include/object.h \
include/error.h
obj/ft_render.o: src/minirt/ft_render.c include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/object.h include/hit.h
obj/ft_save_bmp.o: src/minirt/ft_save_bmp.c lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/minirt.h \
lib/minilibx_mms_20200219/mlx.h include/exit.h
obj/ft_switch.o: src/minirt/ft_switch.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_write_bmp.o: src/minirt/ft_write_bmp.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h lib/libft/include/libft.h
obj/ft_minirt.o: src/minirt/ft_minirt.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h include/event.h include/console.h
obj/ft_return_object_list.o: src/object/ft_return_object_list.c \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/object.o: src/object/object.c lib/libft/include/libft.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h
obj/ft_destroy_splits.o: src/parse/ft_destroy_splits.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h
obj/ft_parse_ambient.o: src/parse/ft_parse_ambient.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h
obj/ft_parse_camera.o: src/parse/ft_parse_camera.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/parse.h include/utils.h \
include/object.h
obj/ft_parse_color.o: src/parse/ft_parse_color.c lib/libft/include/libft.h \
include/alias.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h include/error.h \
include/parse.h
obj/ft_parse_cylinder.o: src/parse/ft_parse_cylinder.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_integer.o: src/parse/ft_parse_integer.c \
lib/libft/include/libft.h include/alias.h include/error.h \
include/utils.h
obj/ft_parse_light.o: src/parse/ft_parse_light.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_normal.o: src/parse/ft_parse_normal.c lib/libft/include/libft.h \
include/alias.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h include/error.h \
include/parse.h
obj/ft_parse_plane.o: src/parse/ft_parse_plane.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_real.o: src/parse/ft_parse_real.c lib/libft/include/libft.h \
include/alias.h include/error.h include/utils.h
obj/ft_parse_resolution.o: src/parse/ft_parse_resolution.c \
lib/libft/include/libft.h include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/utils.h include/error.h include/parse.h
obj/ft_parse_sphere.o: src/parse/ft_parse_sphere.c include/alias.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_square.o: src/parse/ft_parse_square.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_triangle.o: src/parse/ft_parse_triangle.c include/struct.h \
include/vector.h include/matrix.h include/ray.h include/alias.h \
include/color.h include/error.h include/utils.h include/parse.h \
include/object.h
obj/ft_parse_vector.o: src/parse/ft_parse_vector.c lib/libft/include/libft.h \
include/alias.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h include/error.h \
include/parse.h
obj/ft_pass_line.o: src/parse/ft_pass_line.c include/alias.h include/struct.h \
include/vector.h include/matrix.h include/ray.h include/color.h \
include/error.h
obj/ft_range_integer.o: src/parse/ft_range_integer.c include/alias.h
obj/ft_range_real.o: src/parse/ft_range_real.c include/alias.h
obj/parse.o: src/parse/parse.c lib/libft/include/libft.h \
lib/get_next_line/get_next_line.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/alias.h include/color.h \
include/error.h include/utils.h include/parse.h include/object.h
obj/ft_atof.o: src/utils/ft_atof.c lib/libft/include/libft.h include/alias.h \
include/parse.h include/struct.h include/vector.h include/matrix.h \
include/ray.h include/color.h include/utils.h
obj/ft_atoi_plus.o: src/utils/ft_atoi_plus.c
obj/ft_destroy.o: src/utils/ft_destroy.c include/alias.h
obj/ft_is_color.o: src/utils/ft_is_color.c include/alias.h include/utils.h \
include/error.h include/parse.h include/struct.h include/vector.h \
include/matrix.h include/ray.h include/color.h
obj/ft_is_integer.o: src/utils/ft_is_integer.c lib/libft/include/libft.h \
include/alias.h
obj/ft_is_real.o: src/utils/ft_is_real.c lib/libft/include/libft.h \
include/alias.h
obj/ft_split_rt.o: src/utils/ft_split_rt.c lib/libft/include/libft.h
obj/ft_strslen.o: src/utils/ft_strslen.c
obj/utils_cmp.o: src/utils/utils_cmp.c
obj/utils_str.o: src/utils/utils_str.c include/minirt.h \
lib/minilibx_mms_20200219/mlx.h lib/libft/include/libft.h \
include/struct.h include/vector.h include/matrix.h include/ray.h \
include/alias.h include/color.h
obj/ft_vec3_geometry.o: src/vector/ft_vec3_geometry.c include/vector.h
obj/ft_vec3_length.o: src/vector/ft_vec3_length.c include/vector.h
obj/ft_vec3_multiplication.o: src/vector/ft_vec3_multiplication.c \
include/vector.h include/error.h include/alias.h
obj/ft_vec3_plus_minus.o: src/vector/ft_vec3_plus_minus.c include/vector.h
obj/ft_vec3_set.o: src/vector/ft_vec3_set.c include/vector.h include/alias.h \
include/utils.h
