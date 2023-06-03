NAME = so_long

CC=			gcc
RM=			rm -f
CFLAGS=		-Wall -Wextra -Werror -Wunreachable-code -Ofast
FRAMEWORKS=	-framework OpenGL -framework AppKit
INCLUDES=	$(LIBFT) $(MLX)
LIBS	:= -ldl -lglfw3 -pthread -lm $(MLX)

LIBFT = libft/libft.a
MLX = MLX42/libmlx42.a

#HEADERS	:= -I MLX42/include/MLX42 -lglfw -L /Users/darismen/.brew/opt/glfw/lib/

HEADERS	:= -I libft/includes -I MLX42/include/MLX42 -lglfw -L /Users/darismen/.brew/opt/glfw/lib/

# HEADERS := -I $(MLX)/include -I $(LIBFT)/includes

# LIBS    := $(MLX)/libmlx42.a $(LIBFT)/libft.a -lglfw -lm -L"/Users/darismen/.brew/opt/glfw/lib/"

############################

SOURCES_LIST =	core/main.c core/init.c core/hooks.c \
				core/sprites.c core/utils.c core/draw.c\
				parsing/parsing1.c parsing/parsing2.c parsing/parsing3.c\
				player/draw_player.c player/player_collision.c\
				player/player_move.c

SOURCES_DIR = sources/
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = ./objects/
OBJECTS	= $(SOURCES:.c=.o)

############################

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJECTS) 	
	@$(CC)  $(FRAMEWORKS) $(CFLAGS) $(HEADERS) $(OBJECTS) $(INCLUDES) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

exe:
	@make
	./$(NAME) ./maps/1.ber

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $< -I $(INCLUDES)

$(LIBFT):
	@make -C libft/ all

$(MLX):
	@make -C MLX42/ all

$(DEBUG_MLX):
	@cmake  -s re DDEBUG=1 -C MLX42/ all

clean:
	@rm -f $(NAME)
	@rm -f debug
	@find sources -name "*.o" -delete
	@echo "$(RED)Deleting all .o Files$(RESET)"
	
fclean:		clean
	@make -C libft/ fclean
#	@make -C MLX42/ clean
#	@rm -f $(MLX)
	
re:		fclean all

.PHONY:	all clean fclean re

push:
	git add .
	git commit -m "push"
	git push origin master

test: $(LIBFT) $(OBJECTS) 
	@$(CC) -g $(FRAMEWORKS) $(CFLAGS) $(OBJECTS) $(LIBS) $(HEADERS) test.c -o test $(INCLUDES)
	./test

debug: $(LIBFT) $(DEBUG_MLX) $(OBJECTS) 
	@$(CC) -g $(FRAMEWORKS) $(CFLAGS) $(HEADERS) $(OBJECTS) $(INCLUDES) -o debug
	lldb ./debug ./maps/1.ber

############################

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

############################