NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

MLX_DIR = minilibx-linux
LIBFT_DIR = libft

SRC = src/main.c \
		src/hooks.c\
		src/file_handling.c\
		src/file_handling2.c\

OBJ = $(SRC:.c=.o)

MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

.PHONY: all clean fclean re libft mlx

all: libft mlx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(MLX_FLAGS)

%.o: %.c includes/fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
