CC=gcc
CFLAGS=-Wall -Wextra -Werror
MAKE=/usr/bin/make
NAME=fdf

OBJ_DIR=objs
SRC_DIR=srcs
LIB_DIR=libs
INCLUDE_DIR=includes

FT_PATH=libft
MLX_PATH=minilibx

SRCS=camera.c gb_collection.c graphics.c images.c img_graphics.c key_events.c \
key_functions_1.c key_functions_2.c key_functions_3.c main.c map.c \
map_projection.c matrix.c tools.c transformations.c vectors.c
OBJS=$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS=-lft -lm -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re libft minilibx


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@echo "=================================================="
	@echo
	@echo "Objects generation : ""\x1B[38;5;40m""Done.""\x1B[0m"
	@echo
	@$(MAKE) libft
	@$(MAKE) minilibx
	@echo "                 Building $@..."
	@echo "--------------------------------------------------"
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_DIR) $(LIBS)
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo
	@echo "=================================================="

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $^ -o $@ -c -I$(INCLUDE_DIR)

$(LIB_DIR):
	@mkdir $@

libft: $(LIB_DIR)
	@echo "                Compiling libft..."
	@echo "--------------------------------------------------"
	$(MAKE) -C $(FT_PATH)
	@echo
	@echo "                Creating symlink..."
	@echo "--------------------------------------------------"
	cd $(LIB_DIR) && ln -fs ../$(FT_PATH)/libft.a
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo

minilibx: $(LIB_DIR)
	@echo " Compiling minilibx... (warnings in $(MLX_PATH)/logs)"
	@echo "--------------------------------------------------"
	$(MAKE) -C $(MLX_PATH) 2> $(MLX_PATH)/logs
	@echo
	@echo "               Creating symlink..."
	@echo "--------------------------------------------------"
	cd $(LIB_DIR) && ln -fs ../$(MLX_PATH)/libmlx.a
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo

clean:
	@echo "                Cleaning libft..."
	@echo "--------------------------------------------------"
	$(MAKE) clean -C $(FT_PATH)
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo
	@echo "                Cleaning minilibx..."
	@echo "--------------------------------------------------"
	$(MAKE) clean -C $(MLX_PATH)
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo
	@echo "                Removing objects..."
	@echo "--------------------------------------------------"
	rm -f $(OBJS)
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo

fclean: clean
	@echo "                 Removing $(NAME)..."
	@echo "--------------------------------------------------"
	rm -f $(NAME)
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo
	@echo "                Removing libft..."
	@echo "--------------------------------------------------"
	rm -f $(FT_PATH)/libft.a
	@echo
	@echo "                Removing minilibx"
	@echo "--------------------------------------------------"
	rm -f $(MLX_PATH)/minilibx.a
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo
	@echo "                Removing symlinks"
	@echo "--------------------------------------------------"
	rm -f $(LIB_DIR)/*
	@echo
	@echo "\x1B[38;5;40m""Done.""\x1B[0m"
	@echo

re: fclean all
