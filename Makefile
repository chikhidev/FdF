GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf
CFLAGS = -Wall -Wextra -Werror -Imlx #-O2
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

BSRC = 	bonus/config_bonus.c \
		bonus/draw_bonus.c \
		bonus/string_bonus.c \
		bonus/string2_bonus.c \
      	bonus/geo_bonus.c \
      	bonus/cartesian_bonus.c \
      	bonus/read_bonus.c \
      	bonus/error_bonus.c \
		bonus/rendering_sides_bonus.c \
	  	bonus/main_bonus.c \
	  	bonus/events_listener_bonus.c \
		bonus/events/input_bonus.c \
	  	bonus/events/conf_bonus.c \
		bonus/events/moving_bonus.c \
		bonus/events/renderer_bonus.c \
		bonus/events/rotation_bonus.c \
		bonus/events/cmd_bonus.c

SRC = 	manda/config.c \
		manda/draw.c \
		manda/string.c \
		manda/string2.c \
      	manda/geo.c \
      	manda/cartesian.c \
      	manda/read.c \
      	manda/error.c \
	  	manda/main.c \

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
GNL = get_next_line.o
LIBFT = libft.a
FTPRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(OBJ) $(FTPRINTF)
	@echo "$(GREEN)Compiling and linking $(NAME) 🤓☁️$(RESET)"
	@cc $(OBJ) $(GNL) $(LIBFT) $(FTPRINTF) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Done! -----------------------------------------$(RESET)"

bonus: $(LIBFT) $(GNL) $(BOBJ) $(FTPRINTF)
	@echo "$(GREEN)Compiling and linking bonus $(NAME)_bonus 🤓☁️$(RESET)"
	@cc $(BOBJ) $(GNL) $(LIBFT) $(FTPRINTF) -o $(NAME)_bonus $(LDFLAGS)
	@echo "$(GREEN)Done! -----------------------------------------$(RESET)"

OBJ: SRC
	@echo "$(YELLOW)Compiling $< 🛠️$(RESET)"
	@cc -c $< $(CFLAGS) -o $@

BOBJ: BSRC
	@echo "$(YELLOW)Compiling bonus$< 🛠️$(RESET)"
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
	@rm -f $(NAME) $(NAME)_bonus

build: all bonus clean

re: clean all
