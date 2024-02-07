GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf
CFLAGS = -Wall -Wextra -Werror -Imlx -O3
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

BSRC = 	src/config.c \
		src/draw.c \
		src/string.c \
		src/string2.c \
      	src/geo.c \
      	src/cartesian.c \
      	src/read.c \
      	src/error.c \
		src/rendering_sides.c \
	  	src/main.c \
	  	src/events_listener.c \
		src/events/input.c \
	  	src/events/conf.c \
		src/events/moving.c \
		src/events/renderer.c \
		src/events/rotation.c \
		src/events/cmd.c \
		src/background.c

BOBJ = $(BSRC:.c=.o)
GNL = get_next_line.o
LIBFT = libft.a
FTPRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(BOBJ) $(FTPRINTF)
	@echo "$(GREEN)Compiling and linking 🤓☁️$(RESET)"
	@cc $(BOBJ) $(GNL) $(LIBFT) $(FTPRINTF) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Done! -----------------------------------------$(RESET)"

OBJ: SRC
	@echo "$(YELLOW)Compiling $< 🛠️$(RESET)"
	@cc -c $< $(CFLAGS) -o $@

BOBJ: BSRC
	@echo "$(YELLOW)Compiling $< 🛠️$(RESET)"
	@cc -c $< $(CFLAGS) -o $@

libft.a:
	@echo "$(YELLOW)Compiling libft 🛠️$(RESET)"
	@make -C ./libft && mv ./libft/libft.a .

get_next_line.o:
	@echo "$(YELLOW)Compiling get_next_line 🛠️$(RESET)"
	@cc -c ./get_next_line/get_next_line.c $(CFLAGS) -o get_next_line.o

libftprintf.a:
	@echo "$(YELLOW)Compiling ft_printf 🛠️$(RESET)"
	@make -C ./ft_printf && mv ./ft_printf/libftprintf.a .

clean:
	@echo "$(RED)Removing objects and executable 🧹$(RESET)"
	@make -C ./libft clean
	@make -C ./ft_printf clean
	@rm -f $(OBJ) $(GNL) $(LIBFT) $(FTPRINTF) $(BOBJ)

fclean: clean 
	@echo "$(RED)Removing executable 😢$(RESET)"
	@rm -f $(NAME)

build: all clean

re: clean all
