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


all: $(NAME)

$(NAME): $(OBJS)
	@echo "Objects generation done."
	$(MAKE) libft
	$(MAKE) minilibx
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_DIR) $(LIBS)
	@echo "Done."
	@echo

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $^ -o $@ -c -I$(INCLUDE_DIR)

libft:
	@echo "Compiling libft..."
	@$(MAKE) -C $(FT_PATH)
	@echo "Creating symlink..."
	@ln -fs $(FT_PATH)/libft.a $(LIB_DIR)
	@echo "Done."

minilibx:
	@echo "Compiling minilibx..."
	@$(MAKE) -C $(MLX_PATH)
	@echo "Creating symlink..."
	@ln -fs $(MLX_PATH)/libmlx.a $(LIB_DIR)
	@echo "Done."

clean:
	@echo "Cleaning libft"
	@$(MAKE) clean -C $(FT_PATH)
	@echo "Done."
	@echo "Cleaning minilibx"
	@$(MAKE) clean -C $(MLX_PATH)
	@echo "Done."
	@echo
	@echo "Removing objects"
	@rm -f $(OBJS)
	@echo "Done."
	@echo

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@echo "Done."
	@echo
	@echo "Removing libft"
	@rm -f $(FT_PATH)/libft.a
	@echo "Done."
	@echo "Removing minilibx"
	@rm -f $(MLX_PATH)/minilibx.a
	@echo "Done."
	@echo "Removing symlinks"
	@rm -f $(LIB_DIR)/*
	@echo "Done."
	@echo

re: fclean all
