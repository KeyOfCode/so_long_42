################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	:= so_long
CC		:= gcc -g
RM 		:= rm -f
FLAGS	:= -Wall -Wextra -Werror
HEADERS	:= -I./include/ -I $(LIBMLX)/include
LIBMLX  := ./MLX42
MLX		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT 	= 	libft/libft.a
FT		:= ./libft/libft.a -Llibft/

CACHE_DIR := ./cache

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC_DIR		= sources
SRCS_LIST =		core/main.c core/init.c core/hooks.c \
				core/sprites.c core/utils.c core/draw.c\
				parsing/parsing1.c parsing/parsing2.c parsing/parsing3.c\
				player/draw_player.c player/player_collision.c\
				player/player_move.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_LIST))

OBJS 	:= $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

TEST_TRGT	= maps/1.ber

################################################################################
#                                  Makefile  objs                              #
################################################################################

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@mkdir -p $(CACHE_DIR)/mesa_shader_cache
	@$(CC) $(HEADERS) $(FLAGS) -o $(NAME) $(OBJS) $(FT) $(MLX) 
	@echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

$(MLX):
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C libft all

all:		$(NAME)

bonus:		all

clean:
	@ $(RM) *.o */*.o */*/*.o
	@ rm -rf $(CACHE_DIR)
	@ rm -rf $(LIBMLX)/build
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
	@ $(RM) $(NAME)
	@make -C libft fclean
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re

exe:
	@make
	./$(NAME) $(TEST_TRGT)

val: $(OBJS) 
	$(CC) $(FLAGS) -o val $(OBJS)
	$(VALGRIND)  $(VAL_FLAGS)


CLR_RMV		:= \033[0m
RED 		:= \033[1;31m
GREEN 		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM 			:= rm -f
