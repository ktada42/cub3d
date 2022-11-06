CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:%.c=%.o)
NAME = libftprintf.a
RM = rm -f

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@
	
$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJS)
	$(RM) $(NAME)
	
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

re: fclean all

.PHONY: all  clean fclean re
