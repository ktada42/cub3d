/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:33:25 by kaou              #+#    #+#             */
/*   Updated: 2022/11/10 00:18:24 by ktada            ###   ########.fr       */
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

//todo サイズを変える
# define WIDTH 800
# define HEIGHT 600
# define MAP_WIDTH 480
# define MAP_HEIGHT 360
//todo
# define CELL_SIZE 32
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
# define KEY_TURN_L 'j'

//k
# define KEY_TURN_R 'k'

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

typedef struct s_state {
	void		*mlx;
	void		*win;
	t_color		*floor_color;
	t_color		*ceil_color;
	char		*path_no_texture;
	char		*path_ea_texture;
	char		*path_so_texture;
	char		*path_we_texture;
	bool		press_key_left;
	bool		press_key_up;
	bool		press_key_right;
	bool		press_key_down;
	bool		press_key_turn_l;
	bool		press_key_turn_r;
	char		start_player_dir;
	double		player_angle;
	t_vector	*player_pos;
	long long	cur_frame;
	t_img_data	img;
	char		map[MAP_MAX_HEIGHT][MAP_MAX_WIDTH];
}	t_state;

//action
void	try_apply_move(t_state	*state);
void	apply_turn(t_state	*state);

//color
t_color	*str_to_color(char *str);
t_color	*make_color(int r, int g, int b);

//config
bool	is_texture_config(t_state *state, char **file_text, size_t i, size_t j);
void	parse_texture(t_state *state, char **file_text, size_t i, size_t j);
bool	is_no_part(char **file_text, size_t f, size_t t);
void	setup_no_texture(t_state *state, char **file_text, size_t f, size_t t);
bool	is_ea_part(char **file_text, size_t f, size_t t);
void	setup_ea_texture(t_state *state, char **file_text, size_t f, size_t t);
bool	is_so_part(char **file_text, size_t f, size_t t);
void	setup_so_texture(t_state *state, char **file_text, size_t f, size_t t);
bool	is_we_part(char **file_text, size_t f, size_t t);
void	setup_we_texture(t_state *state, char **file_text, size_t f, size_t t);
bool	is_floor_part(char **file_text, size_t f, size_t t);
void	setup_floor_color(t_state *state, char **file_text, size_t f, size_t t);
bool	is_ceil_part(char **file_text, size_t f, size_t t);
void	setup_ceil_color(t_state *state, char **file_text, size_t f, size_t t);
char	**setup_split(char **s, char sep, int *cnt);
bool	is_map_part(char **file_text, size_t f, size_t t);
void	setup_map(t_state *state, char **file_text, size_t f, size_t t);

//draw
void	draw_pixel(t_img_data *data, int x, int y, int color);
void	draw_view(t_state *state);
void	init_canvas(t_state *state);

//get_coordinate
t_vector	*cell_top_left(size_t h, size_t w);


//string
int		ft_str_cnt(char *s, char c);
int		ft_str_cnt_set(char *s, char *set);
int		ft_str_cnt_set_2d(char **s, size_t f, size_t t, char *set);
void	strcpy_2d(char **dst, char **src, size_t f, size_t t);

//utils.c
void		debug_state_info(t_state *state);
bool		starts_with(char *str, char *prefix);
void		free_2d_array(char **ar);
void		fill(char **dst, size_t height, size_t width, char v);

//malloc.c
void		*my_malloc(size_t type_size, size_t count);

//map
bool		has_wall_at(t_state *state, t_vector *pos);
void		check_valid_map(t_state *state, char **file_text, size_t f, size_t t);
void		set_player_start_position(char **file_text, size_t f, size_t t, t_grid_pos *pos);
void		setup_config(t_state *state, int argc, char **argv);

//math
double		normalize_theta(double theta);
double		deg_to_theta(double deg);
double		theta_to_deg(double theta);

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
void 		exit_print(char *mes);

//vector
t_vector	*add(t_vector *lhs, t_vector *rhs);
t_vector	*sub(t_vector *lhs, t_vector *rhs);
t_vector	*scalar_mul(t_vector *lhs, double r);
t_vector	*scalar_div(t_vector *lhs, double r);
t_vector	*rotate(t_vector *vec, double theta);
t_vector	*make_vector(double x, double y);
void		copy_vector(t_vector *dst, t_vector *src);
double		length(t_vector	*vec);
t_vector	*normalize_vector(t_vector *vec);

//main
void		init_press_keys(t_state *state);

int			close_all(int keycode, t_state *state);

#endif