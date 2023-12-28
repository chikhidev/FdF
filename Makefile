GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf
CFLAGS = -Wall -Wextra -Werror -Imlx
#-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft.a
SRC = 	draw.c \
		main.c \
		string.c \
		geo.c \
		cartesian.c \
		read.c \
		ft_realloc.c
OBJ = $(SRC:.c=.o)
GNL = get_next_line.o
MLX = libmlx.a
LIBFT = libft.a
LIBS = libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(MLX)
	@echo "$(GREEN)Compiling and linking $(NAME) 🤓☁️$(RESET)"
	@cc $(OBJ) $(GNL) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS) -fsanitize=address
	@echo "$(GREEN)Done! -----------------------------------------$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $< 🛠️$(RESET)"
	@cc -c $< $(CFLAGS) -o $@

libft.a:
	@echo "$(YELLOW)Compiling libft 🛠️$(RESET)"
	@make -C ./libft && mv ./libft/libft.a .

libmlx.a:
	@echo "$(YELLOW)Compiling mlx 🛠️$(RESET)"
	@make -C ./minilibx-linux && mv ./minilibx-linux/libmlx.a .

get_next_line.o:
	@echo "$(YELLOW)Compiling get_next_line 🛠️$(RESET)"
	@cc -c ./get_next_line/get_next_line.c $(CFLAGS) -o get_next_line.o

clean:
	@echo "$(RED)Removing objects and executable 🧹$(RESET)"
	@make -C ./libft clean
	@rm -f $(OBJ) $(GNL) $(LIBFT) $(MLX)

fclean: clean 
	@echo "$(RED)Removing $(NAME) 😢$(RESET)"
	@rm -f $(NAME)

build: all clean
	
re: clean all
