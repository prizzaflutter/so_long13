NAME= so_long

SRC_MANDATORY=	./Mandatory/so_long.c ./Mandatory/srcs/render/mlx.c  ./Mandatory/srcs/render/rendering.c ./Mandatory/srcs/player/is_valid_move.c ./Mandatory/srcs/player/key_handler.c ./Mandatory/srcs/map/map_utils.c  \
			./Mandatory/helps/fill_map.c ./Mandatory/helps/get_map_heigth.c ./Mandatory/helps/get_map_width.c ./Mandatory/helps/init_map.c ./Mandatory/helps/validate_map.c \
			./lib/function_from_lib/ft_putstr.c ./lib/function_from_lib/ft_putchar.c ./lib/function_from_lib/ft_strnstr.c \
			./lib/get_next_line/get_next_line.c  ./lib/get_next_line/get_next_line_utils.c 

SRC_BONUS= ./Bonus/so_long_bonus.c ./Bonus/srcs_bonus/render_bonus/mlx.c  ./Bonus/srcs_bonus/render_bonus/rendering.c ./Bonus/srcs_bonus/player_bonus/is_valid_move.c ./Bonus/srcs_bonus/player_bonus/key_handler.c ./Bonus/srcs_bonus/map_bonus/map_utils.c  \
			./Bonus/helps_bonus/fill_map.c ./Bonus/helps_bonus/get_map_heigth.c ./Bonus/helps_bonus/get_map_width.c ./Bonus/helps_bonus/init_map.c ./Bonus/helps_bonus/validate_map.c \
			./lib/function_from_lib/ft_putstr.c ./lib/function_from_lib/ft_putchar.c ./lib/function_from_lib/ft_strnstr.c \
			./lib/get_next_line/get_next_line.c  ./lib/get_next_line/get_next_line_utils.c 

OBJ_MANDATORY= $(SRC_MANDATORY:.c=.o)

OBJ_BONUS= $(SRC_BONUS:.c=.o)

Flags= -Wall -Werror -Wextra -Imlx

MLX= -L. -lmlx -framework OpenGL -framework AppKit

CC= cc

RM= rm -rf 

all: $(NAME)

$(NAME): $(OBJ_MANDATORY)
	$(CC) $(Flags) $(OBJ_MANDATORY) $(MLX) -o $(NAME)

%.o: %.c ./Mandatory/so_long.h
	$(CC) $(Flags) -c $< -o $@

bonus: $(OBJ_BONUS) ./Bonus/so_long_bonus.h
	$(CC) $(Flags) $(OBJ_BONUS) $(MLX) -o $(NAME)

clean:
	$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean 
	$(RM) $(NAME) $(bonus)
	
re: fclean all bonus