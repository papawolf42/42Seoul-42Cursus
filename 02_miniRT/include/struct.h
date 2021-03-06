/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:54:12 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 01:17:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "vector.h"
# include "matrix.h"
# include "ray.h"
# include "alias.h"
# include "color.h"

typedef struct s_image			t_image;
typedef struct s_ctrl			t_ctrl;
typedef struct s_canvas			t_canvas;
typedef struct s_ambient		t_ambient;
typedef struct s_scene			t_scene;
typedef struct s_pth_data		t_pth_data;

typedef struct s_hit_record		t_hit_rec;
typedef struct s_object_list	t_object_list;

typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_square			t_square;
typedef struct s_cylinder		t_cylinder;
typedef struct s_triangle		t_triangle;

typedef struct s_var_render		t_var_render;
typedef struct s_var_phong		t_var_phong;
typedef struct s_var_sphere		t_var_sphere;
typedef struct s_var_cylinder	t_var_cylinder;
typedef struct s_var_triangle	t_var_triangle;

typedef enum e_object_type		t_object_type;

typedef struct s_pft_parse		t_pft_parse;

struct							s_pft_parse
{
	char			*id;
	t_bool			(*parse)(t_scene *scene, char **splits);
};

enum							e_object_type
{
	no = 0,
	cam = 1,
	l = 2,
	sp = 3,
	pl = 4,
	sq = 5,
	cy = 6,
	tr = 7
};

struct							s_image
{
	void			*img_ptr;
	char			*data;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
};

struct							s_ctrl
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			img;
	t_scene			*scene;
	char			mode;
	t_object_list	*object_selected;
	t_bool			bool_multi_threading;
	t_bool			bool_anti_aliasing;
	t_bool			bool_fish_eye;
	double			unit_move;
	double			unit_rotate;
	double			unit_resize;
};

struct							s_canvas
{
	int				width;
	int				height;
	int				max_w;
	int				max_h;
	double			aspect_ratio;
};

struct							s_ambient
{
	double			ratio;
	t_color			color;
};

struct							s_scene
{
	int				flag_declare;
	t_canvas		canv;
	t_ambient		ambient;
	t_object_list	*light_list;
	t_object_list	*camera_list;
	t_object_list	*object_list;
	int				idx_l;
	int				idx_c;
	int				idx_o;
	int				count_l;
	int				count_c;
	int				count_o;
	char			filter;
	t_color			*data_aa;
};

struct							s_pth_data
{
	int				lane;
	int				count;
	int				progress;
	t_ctrl			*ctrl;
};

struct							s_object_list
{
	void			*object;
	t_object_type	type;
	t_object_list	*next;
};

struct							s_hit_record
{
	t_point3		p;
	t_vec3			normal;
	double			t_min;
	double			t_max;
	double			t;
	t_front			front_face;
	t_color			color;
	t_object_list	*object_list;
};

struct							s_triangle
{
	t_point3		a;
	t_point3		b;
	t_point3		c;
	t_vec3			ab;
	t_vec3			bc;
	t_vec3			ca;
	t_vec3			normal;
	t_color			color;
};

struct							s_cylinder
{
	t_point3		center_bottom;
	t_point3		center_top;
	t_vec3			axis;
	double			radius;
	double			height;
	t_color			color;
};

struct							s_square
{
	t_point3		center;
	t_vec3			normal;
	t_vec3			axis_up;
	double			side_len;
	t_color			color;
	t_vec3			span_a;
	t_vec3			span_b;
};

struct							s_plane
{
	t_point3		point;
	t_vec3			normal;
	t_color			color;
};

struct							s_sphere
{
	t_point3		center;
	double			radius;
	t_color			color;
};

struct							s_light
{
	t_point3		p;
	double			ratio;
	t_color			color;
};

struct							s_camera
{
	t_point3		origin;
	t_vec3			normal;
	double			fov;
	t_mat44			mat_c2w;
};

struct							s_var_render
{
	int				x;
	int				y;
	t_ray			ray;
	t_color			color;
	t_camera		*camera;
	char			*data;
};

struct							s_var_phong
{
	t_color			diffuse;
	t_color			specular;
	t_color			light_intensity;
	t_vec3			to_light;
	t_vec3			to_view;
	t_vec3			reflect;
	double			kd;
};

struct							s_var_sphere
{
	t_vec3			oc;
	double			a;
	double			half_b;
	double			c;
	double			discriminant;
	double			sqrtd;
};

struct							s_var_cylinder
{
	t_vec3			v;
	t_vec3			w;
	t_vec3			h;
	double			a;
	double			half_b;
	double			c;
	double			discriminant;
	double			root;
	double			sqrtd;
};

struct							s_var_triangle
{
	double			proj_unit;
	double			proj_len;
	double			root;
	t_vec3			p;
	t_vec3			na;
	t_vec3			nb;
	t_vec3			nc;
};

t_mat44							ft_getmat_c2w(t_camera *cam, t_vec3 axis_up);

#endif
