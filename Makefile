NAME = cub3d

CC = gcc

SRCS =  \
srcs/action/apply_move.c \
srcs/action/apply_turn.c \
srcs/color/make.c \
srcs/config/already_set_map.c \
srcs/config/already_set_texture.c \
srcs/config/already_set_textures.c \
srcs/config/aready_set_color.c \
srcs/config/check_valid_map.c \
srcs/config/check_valid_map_utils.c \
srcs/config/is_color_config.c \
srcs/config/is_map_config.c \
srcs/config/is_texture_config.c \
srcs/config/setup_color.c \
srcs/config/setup_config.c \
srcs/config/setup_map.c \
srcs/config/setup_map_utils.c \
srcs/config/setup_texture.c \
srcs/debug/print.c \
srcs/draw/draw_column.c \
srcs/draw/draw_minimap.c \
srcs/draw/draw_pixel.c \
srcs/draw/draw_view.c \
srcs/draw/draw_view_utils.c \
srcs/draw/minidraw_cell.c \
srcs/grid/get_grid_pos.c \
srcs/grid/make_grid_pos.c \
srcs/grid/utils.c \
srcs/image/load_texture.c \
srcs/init_state.c \
srcs/key/is_move_key.c \
srcs/key/is_turn_key.c \
srcs/key/key_handler.c \
srcs/main.c \
srcs/map/get_coordinate.c \
srcs/map/has_wall_at.c \
srcs/math/theta.c \
srcs/math/utils.c \
srcs/ray/get_ray_hit.c \
srcs/ray/get_ray_hit_horizontal.c \
srcs/ray/get_ray_hit_vertical.c \
srcs/ray/make_ray_hit.c \
srcs/ray/ray_dir.c \
srcs/ray/ray_hit_utils.c \
srcs/string/str_cnt.c \
srcs/string/utils.c \
srcs/utils.c \
srcs/utils/malloc.c \
srcs/vector/calc.c \
srcs/vector/calc_assign.c \
srcs/vector/length.c \
srcs/vector/make.c \
srcs/vector/normalize.c \
srcs/vector/rotate.c \

OBJS = $(SRCS:%.c=%.o)
MLX_DIR = mlx
LIB = ./includes/library/library.a
LIB_DIR = ./includes/library

%.o: %.c
	@$(CC) -g -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	clear
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR) 2> /dev/null
	@$(CC) $(OBJS) $(LIB) -Lmlx -L/usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(NAME)
	$(RM) $(OBJS)

all : $(NAME)

bonus : $(NAME)

ok1:
	./cub3d test_files/ok_map/simple_map.cub
norm:
	norminette srcs/
	norminette includes/
	
re: fclean all

.PHONY: all clean fclean re bonus norm ok1