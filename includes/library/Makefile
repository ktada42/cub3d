CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c  ./get_next_line/get_file_text.c
OBJS = $(SRCS:%.c=%.o)
NAME = library.a
RM = rm -f

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@
	
$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf_dir
	cp ft_printf_dir/libftprintf.a $(NAME)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

fclean:
	$(MAKE) fclean -C ./ft_printf_dir
	$(RM) $(OBJS)
	$(RM) $(NAME)

clean:
	$(MAKE) clean -C ./ft_printf_dir
	$(RM) $(OBJS)

re: fclean all

.PHONY: all  clean fclean re
