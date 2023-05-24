NAME = so_long

CC=			gcc
RM=			rm -f
CFLAGS=		-Wall -Wextra -Werror -Wunreachable-code -Ofast
FRAMEWORKS=	-framework OpenGL -framework AppKit
INCLUDES=	$(LIBFT) $(MINILIBX)

LIBFT = libft/libft.a
MINILIBX = MLX42/libmlx42.a

LIBMLX	:= ./lib/MLX42

HEADERS	:= -I MLX42/include/MLX42 -lglfw -L /Users/darismen/.brew/opt/glfw/lib/

############################

SOURCES_LIST =	core/main.c core/init.c core/hooks.c \
				core/sprites.c core/utils.c core/draw.c\
				parsing/parsing1.c parsing/parsing2.c parsing/parsing3.c\
				player/draw_player.c player/player_collision.c\
				player/player_move.c

# core/hooks.c
# other/draw_wall.c other/draw_bg.c other/draw_coin.c

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

test: $(LIBFT) $(MINILIBX) clean
	@$(CC) -g $(FRAMEWORKS) $(CFLAGS) $(HEADERS) test.c -o test $(INCLUDES)
	./test

debug: $(LIBFT) $(DEBUG_MLX) clean
	@$(CC) -g $(FRAMEWORKS) $(CFLAGS) $(HEADERS) $(SOURCES) -o debug $(INCLUDES)
	lldb ./debug ./maps/1.ber

push:
	git add .
	git commit -m "push"
	git push origin master

$(NAME): $(LIBFT) $(MINILIBX) clean
	@$(CC) $(FRAMEWORKS) $(CFLAGS) $(HEADERS) $(SOURCES) -o $(NAME) $(INCLUDES) 
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
##	./$(NAME) ./maps/error.ber ./maps/1.ber

%.o: %.c
	@${CC} ${FLAGS}  -o $@ -c $< $(HEADERS)

$(LIBFT):
	@make -C libft/ all
	
minilibx:
	@make -C MLX42/ all

$(DEBUG_MLX):
	@cmake  -s re DDEBUG=1 -C MLX42/ all

clean:
	
	@rm -f $(NAME)
	@rm -f debug
	@rm -rf $(OBJECTS_DIR)
	@echo "$(RED)Deleting all .o Files$(RESET)"
	
fclean:		clean
	@make -C libft/ clean
	@make -C MLX42/ clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	
re:		fclean all

.PHONY:	all clean fclean re