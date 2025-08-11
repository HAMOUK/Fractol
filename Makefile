

NAME = fractol

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
  parsing.c \
  calculate.c \
  draw.c \
  handle_window1.c \
  handle_window2.c \
  handle_colors.c \
  handle_fractals.c 
 
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) loading
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@echo "🗑️ Removing object files from fractol..."
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@$(MAKE) clean -C $(MLX_DIR) --silent

fclean: clean
	@echo "🧺 Full clean: removing binary and libft archive..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent

re: fclean all

.PHONY: all clean fclean re

loading:
	@echo "✅ Compilation terminée avec succès !"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@