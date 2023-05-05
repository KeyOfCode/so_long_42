NAME = so_long

CC=			gcc
RM=			rm -f
CFLAGS=		-Wall -Wextra -Werror -Wunreachable-code -Ofast
FRAMEWORKS=	-framework OpenGL -framework AppKit
INCLUDES=	$(LIBFT) $(MINILIBX)

LIBFT = libft42/libft.a
MINILIBX = MLX42/libmlx42.a

LIBMLX	:= ./lib/MLX42

HEADERS	:= -I MLX42/include/MLX42 -lglfw -L /Users/darismen/.brew/opt/glfw/lib/

############################

SOURCES_LIST =	main.c init.c hooks.c\

# init.c hooks.c mlx_test.c

SOURCES_DIR = ./sources/
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = objects/
OBJECTS	= $(addprefix objects/, $(SOURCES_LIST:.c=.o))

############################

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

############################

all: libft minilibx $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) clean
	$(CC) $(FRAMEWORKS) $(CFLAGS) $(HEADERS) $(SOURCES) -o $(NAME) $(INCLUDES) 
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
	./$(NAME) maps/basictest.fdf

%.o: %.c
	@${CC} ${FLAGS}  -o $@ -c $< $(HEADERS)

libft:
	@make -C libft42/ all
	
minilibx:
	@make -C MLX42/ all

clean:
	
	@rm -f $(NAME)
	@rm -rf $(OBJECTS_DIR)
	@echo "$(RED)Deleting all .o Files$(RESET)"
	
fclean:		clean
	@make -C libft42/ clean
	@make -C MLX42/ clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	
re:		fclean all

.PHONY:	all clean fclean re