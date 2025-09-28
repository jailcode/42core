# Name of the executable
NAME = app

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Source and object files
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# MiniLibX
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS_LINUX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_FLAGS_MACOS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Detect OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
else
	MLX_FLAGS = $(MLX_FLAGS_MACOS)
endif

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

