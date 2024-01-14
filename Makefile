GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf
CFLAGS = -Wall -Wextra -Werror -Imlx 
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRC = 	config.c \
		draw.c \
		string.c \
		geo.c \
      	cartesian.c \
      	read.c \
		free_exit.c \
      	error.c \
	  	main.c

BSRC = 	config.c \
		draw.c \
		string.c \
      	geo.c \
      	cartesian.c \
      	read.c \
		free_exit.c \
      	error.c \
	  	bmain.c \
	  	events_listener.c \
	  	events/conf.c events/moving.c events/renderer.c events/rotation.c

OBJ = $(SRC:.c=.o)
GNL = get_next_line.o
LIBFT = libft.a
FTPRINTF = libftprintf.a
BONUS_OBJ = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(OBJ) $(FTPRINTF)
	@echo "$(GREEN)Compiling and linking $(NAME) 🤓☁️$(RESET)"
	@cc $(OBJ) $(GNL) $(LIBFT) $(FTPRINTF) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Done! -----------------------------------------$(RESET)"

OBJ: SRC
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

bonus: $(LIBFT) $(GNL) $(FTPRINTF) $(BONUS_OBJ)
	@echo "$(GREEN)Compiling and linking bonus executable 🤓☁️$(RESET)"
	@cc $(BONUS_OBJ) $(GNL) $(LIBFT) $(FTPRINTF) -o bonus_$(NAME) $(LDFLAGS)
	@echo "$(GREEN)Done! -----------------------------------------$(RESET)"

BONUS_OBJ: BSRC
	@echo "$(YELLOW)Compiling $< 🛠️$(RESET)"
	@cc -c $< $(CFLAGS) -o $@

clean:
	@echo "$(RED)Removing objects and executable 🧹$(RESET)"
	@make -C ./libft clean
	@rm -f $(OBJ) $(GNL) $(LIBFT) $(FTPRINTF) $(BONUS_OBJ)

fclean: clean 
	@echo "$(RED)Removing $(NAME) and bonus executable 😢$(RESET)"
	@rm -f $(NAME) bonus_$(NAME)

build: all clean

re: clean all
