NAME = fdf
CC = cc
CCFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLXFLAGS = -L $(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lm
INCLUDES = -Iinclude

SRCS = src/main.c src/utils.c src/window.c
OBJS = $(SRCS:.c=.o)

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning minilibx..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	else \
		echo "minilibx already exists, skipping clone."; \
	fi

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CCFLAGS) $(OBJS) $(MLXFLAGS) $(INCLUDES) -o $(NAME)
	@echo "Compilation finished: $(NAME)"

clean:
	@rm -rf $(OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_DIR)
	@echo "Executable and minilibx removed."

re: fclean all

.PHONY: all clean fclean re
