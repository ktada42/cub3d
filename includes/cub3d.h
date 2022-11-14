/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:33:25 by kaou              #+#    #+#             */
/*   Updated: 2022/11/14 23:49:06 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "library/library.h"
# include <mlx.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# define DEBUG 1
# define DEBUG_KEY 1
# define EPS_GRID 0.001f
# define EPS_THETA 0.000001f

# define RED "\x1b[31m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"
//todo サイズを変える
# define WIDTH 800
# define HEIGHT 600
# define MAP_WIDTH 480
# define MAP_HEIGHT 360
//todo
# define FOV_DEG 60
# define PLANE_CELL_SIZE 1
# define WALL_SIZE 10
# define DEFAULT_BG_COLOR 0x0

# define MAP_MAX_HEIGHT 500
# define MAP_MAX_WIDTH 500

//rate
# define MOVE_RATE 3
# define TURN_RATE 0.015
# define UPDATE_INTERVAL 1

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define KEY_ESC 65307
# define KEY_WINDOW_BUTTON 17
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100

//矢印キー
# define KEY_LEFT 65361
# define KEY_KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define CONFIG_ERR_MSG "Error\n"
//j
# define KEY_TURN_L KEY_LEFT

//k
# define KEY_TURN_R KEY_RIGHT

# define KEY_ENTER 32

typedef struct s_color{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector {
	double	x;
	double	y;
}	t_vector;

typedef struct s_grid_pos {
	int	h;
	int	w;
}	t_grid_pos;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_ray_hit{
	void		*wall_texture;
	char		*wall_texture_name;
	t_vector	*hit_pos;
}	t_ray_hit;

typedef struct s_state {
	void		*mlx;
	void		*win;
	t_color		*floor_color;
	t_color		*ceil_color;
	char		*path_no_texture;
	char		*path_ea_texture;
	char		*path_so_texture;
	char		*path_we_texture;
	void		*no_wall_texture;
	void		*ea_wall_texture;
	void		*so_wall_texture;
	void		*we_wall_texture;
	bool		press_key_left;
	bool		press_key_up;
	bool		press_key_right;
	bool		press_key_down;
	bool		press_key_turn_l;
	bool		press_key_turn_r;
	double		player_angle;
	t_vector	*player_pos;
	bool		builded_map;
	size_t		cur_frame;
	t_img_data	img;
	char		**map;
	int			map_grid_height;
	int			map_grid_width;
}	t_state;

//action
void		try_apply_move(t_state	*state);
void		apply_turn(t_state	*state);

//color
t_color		*str_to_color(char *str);
t_color		*make_color(int r, int g, int b);
int			col_to_i(t_color *col);
int			make_color_i(int r, int g, int b);
t_color		*i_to_col(int color_int);

//config
bool		is_texture_config(t_state *state, \
				char **file_text, size_t i, size_t j);
void		parse_texture(t_state *state, char **file_text, size_t i, size_t j);
bool		is_no_config(char **file_text, size_t f, size_t t);
size_t		setup_no_texture(t_state *state, char **file_text, size_t f);
bool		is_ea_config(char **file_text, size_t f, size_t t);
size_t		setup_ea_texture(t_state *state, char **file_text, size_t f);
bool		is_so_config(char **file_text, size_t f, size_t t);
size_t		setup_so_texture(t_state *state, char **file_text, size_t f);
bool		is_we_config(char **file_text, size_t f, size_t t);
size_t		setup_we_texture(t_state *state, char **file_text, size_t f);
bool		is_floor_config(char **file_text, size_t f, size_t t);
size_t		setup_floor_color(t_state *state, char **file_text, size_t f);
bool		is_ceil_config(char **file_text, size_t f, size_t t);
size_t		setup_ceil_color(t_state *state, char **file_text, size_t f);
bool		is_map_config(char **file_text, size_t f, size_t t);
size_t		setup_map(t_state *state, char **file_text, size_t f, size_t t);
bool		is_blank_line(char **file_text, size_t i);
size_t		get_next_blank_line(char **file_text, size_t i);

//debug
void		print_state(t_state *state);
void		print_map(char	**s, size_t h, size_t w);
void		print_vector(char *mes, t_vector *vec);
void		deb(char *s);

//draw
void		draw_pixel_i(t_img_data *data, int x, int y, int color);
void		draw_pixel_color(t_img_data *data, int x, int y, t_color *color);
void		draw_view(t_state *state);

//grid
t_grid_pos	*make_grid_pos(int h, int w);
t_grid_pos	*get_grid_pos1(t_vector *pos);
t_grid_pos	*get_grid_pos2(double x, double y);
bool		inside_grid(t_grid_pos *grid_pos);

//image
void		allocate_image(t_state *state);

//get_coordinate
t_vector	*cell_top_left(size_t h, size_t w);

//string
int			ft_str_cnt(char *s, char c);
int			ft_str_cnt_set(char *s, char *set);
int			ft_str_cnt_set_2d(char **s, size_t f, size_t t, char *set);
void		strcpy_2d(char **dst, char **src, size_t f, size_t t);
void		strcpy_2d_wrap(char **dst, char **src, size_t f, size_t t);

//utils.c
void		debug_state_info(t_state *state);
bool		starts_with(char *str, char *prefix);
void		free_2d_char_array(char **ar);
void		fill(char **dst, size_t height, size_t width, char v);

//malloc.c
void		*my_malloc(size_t type_size, size_t count);
char		**make_2d_char_array(int h, int w);

//map
bool		has_wall_at_strict(t_state *state, double x, double y);
bool		has_wall_at_near(t_state *state, t_vector *pos);
bool		is_too_big_map(char **file_text, size_t f, size_t t);
void		check_arg(int argc, char **argv);
void		check_valid_map(char **file_text, size_t f, size_t t);
void		set_player_start_position(char **file_text, \
									size_t f, size_t t, t_grid_pos *pos);
void		setup_config(t_state *state, int argc, char **argv);
bool		inside_map(t_state *state, t_vector *pos);

//math
double		normalize_rad(double rad);
double		deg_to_rad(double deg);
double		rad_to_deg(double rad);
double		equal_rad(double rad1, double rad2);
double		get_x_by_y_and_rad(double y, double rad);
double		get_y_by_x_and_rad(double x, double rad);
double		ft_abs(double v);

//ray
t_ray_hit	*get_ray_hit(t_state *state, t_vector *player, double ray_rad);
void		free_ray_hit(t_ray_hit *ray_hit);
t_ray_hit	*make_ray_hit(t_state *state, t_vector *hit_pos, \
	bool is_horizontal_query, double ray_rad);
t_ray_hit	*get_ray_hit_horizontal(t_state *state, \
	t_vector *player, double ray_rad);
t_ray_hit	*get_ray_hit_vertical(t_state *state, \
	t_vector *player, double ray_rad);
bool		is_up_dir(double ray_rad);
bool		is_down_dir(double ray_rad);
bool		is_left_dir(double ray_rad);
bool		is_right_dir(double ray_rad);

//frame
//update_frame.c
int			update_frame(t_state	*state);

//key
//check_key.c
bool		is_left_key(int keycode);
bool		is_up_key(int keycode);
bool		is_right_key(int keycode);
bool		is_down_key(int keycode);
bool		is_move_key(int keycode);

bool		key_is_zoom_in(int keycode);
bool		key_is_zoom_out(int keycode);
bool		key_is_zoom(int keycode);
bool		is_turn_key(int keycode);
bool		key_is_reset(int keycode);

//press_key_state
int			handle_key_down(int keycode, t_state *state);
int			handle_key_up(int keycode, t_state *state);

//utils.c
void		exit_print(char *mes);

//vector
t_vector	*add(t_vector *lhs, t_vector *rhs);
t_vector	*sub(t_vector *lhs, t_vector *rhs);
t_vector	*scalar_mul(t_vector *lhs, double r);
t_vector	*scalar_div(t_vector *lhs, double r);

void		add_assign(t_vector *lhs, t_vector *rhs);
void		sub_assign(t_vector *lhs, t_vector *rhs);
void		scalar_mul_assign(t_vector *lhs, double r);
void		scalar_div_assign(t_vector *lhs, double r);

t_vector	*rotate(t_vector *vec, double rad);
t_vector	*make_vector(double x, double y);
void		copy_vector(t_vector *dst, t_vector *src);
double		length(t_vector	*vec);
double		distance(t_vector	*lhs, t_vector *rhs);
t_vector	*normalize_vector(t_vector *vec);

int			close_all(int keycode, t_state *state);
void		init_state(t_state *state, int argc, char **argv);

#endif