NAME = cub3d

CC = gcc
SRCS =  \
		srcs/action/try_move.c \
		srcs/action/turn.c \
		srcs/color/make.c \
		srcs/color/convert.c \
		srcs/config/check_valid_map_utils.c \
		srcs/config/check_valid_map.c \
		srcs/config/is_color_config.c \
		srcs/config/is_map_config.c \
		srcs/config/is_texture_config.c \
		srcs/config/setup_color.c \
		srcs/config/setup_config.c \
		srcs/config/setup_map_utils.c \
		srcs/config/setup_map.c \
		srcs/config/setup_texture.c \
		srcs/debug/print.c \
		srcs/draw/draw_map.c \
		srcs/draw/draw_pixel.c \
		srcs/key/is_move_key.c \
		srcs/key/is_turn_key.c \
		srcs/key/key_handler.c \
		srcs/map/get_coordinate.c \
		srcs/map/has_wall_at.c \
		srcs/math/theta.c \
		srcs/string/str_cnt.c \
		srcs/string/utils.c \
		srcs/utils/malloc.c \
		srcs/vector/calc.c \
		srcs/vector/length.c \
		srcs/vector/make.c \
		srcs/vector/normalize.c \
		srcs/init_state.c \
		srcs/main.c \
		srcs/utils.c \
	
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

re: fclean all

.PHONY: all  clean fclean re bonus