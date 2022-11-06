NAME = cub3d

CC = gcc
SRCS =  \
		

OBJS = $(SRCS:%.c=%.o)
MLX_DIR = mlx
LIB = ./includes/library/library.a
LIB_DIR = ./includes/library

%.o: %.c
	@$(CC) -g -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(OBJS) $(LIB) -Lmlx -L/usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME)

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