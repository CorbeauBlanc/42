CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=fdf
OBJ_PATH= objs
SRC_PATH= srcs
LIB_PATH= libft
SRCS=camera.c gb_collection.c graphics.c images.c img_graphics.c key_events.c \
key_functions_1.c key_functions_2.c key_functions_3.c main.c map.c \
map_projection.c matrix.c tools.c transformations.c vectors.c
OBJS= $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))
MAKE=/usr/bin/make

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Objects generation done."
	$(MAKE) libft
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_PATH) -lft -lm -lmlx -framework OpenGL -framework AppKit
	@echo "Done."
	@echo

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $^ -o $@ -c -Iincludes

libft:
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIB_PATH)
	@echo "Done."

clean:
	@echo "Cleaning libft"
	@$(MAKE) clean -C $(LIB_PATH)
	@echo "Done."
	@echo
	@echo "Removing"
	@echo "$(OBJS)" | tr ' ' '\n'
	@rm -rf $(OBJS)
	@echo "Done."
	@echo

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
	@echo "Done."
	@echo
	@echo "Removing libft"
	@rm -rf $(LIB_PATH)/libft.a
	@echo "Done."
	@echo

re: fclean all
