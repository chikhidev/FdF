NAME = libftprintf.a
SRC = ft_printf.c print_str.c print_num.c print_hex.c
OBJ = $(SRC:%.c=%.o)
FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all