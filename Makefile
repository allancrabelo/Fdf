# === VARIÁVEIS ===

NAME        = fdf
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Diretórios
SRC_DIR     = src
MLX_DIR     = minilibx-linux
LIBFT_DIR   = libft
GNL_DIR     = get_next_line

# Includes e libs
INCLUDES    = -Iinclude -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)
LIBS        = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm \
              -L$(LIBFT_DIR) -lft \
              -L$(GNL_DIR) -lgnl

# Fontes
SRCS        = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/window.c \
	$(SRC_DIR)/parser.c \
	$(SRC_DIR)/parser2.c \
	$(SRC_DIR)/generate_map.c

OBJS        = $(SRCS:.c=.o)

# === REGRAS ===

all: $(MLX_DIR) $(LIBFT_DIR)/libft.a $(GNL_DIR)/libgnl.a $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)
	@echo "✅ Compilado: $(NAME)"

$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Clonando minilibx..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@make -C $(MLX_DIR)

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

$(GNL_DIR)/libgnl.a:
	@make -C $(GNL_DIR)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean
	@echo "🧹 Objetos removidos"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "🧨 Binários e dependências removidas"

re: fclean all

.PHONY: all clean fclean re
