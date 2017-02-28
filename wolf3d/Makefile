CC=gcc
CFLAGS=-Wall -Wextra -Werror
MAKE=/usr/bin/make
NAME=fdf

OBJ_DIR=objs
SRC_DIR=srcs
LIB_DIR=libs
INCLUDE_DIR=includes
INCLUDE_SYS=$$HOME/include/SDL2

FT_PATH=libft
SDL_PATH=SDL2

SRCS=main.c
OBJS=$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBS=-lft -lm -lSDL2

.PHONY: all clean fclean re libft sdl debug-linux debug-mac


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
	@$(CC) $(CFLAGS) $^ -o $@ -c -I$(INCLUDE_DIR) -isystem$(INCLUDE_SYS)

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

sdl: $(LIB_DIR)
	@echo "       Installing SDL in $$HOME"
	@echo "--------------------------------------------------"
	cd SDL2 && CC=./build-scripts/gcc-fat.sh ./configure -q --prefix=$$HOME && \
make && make install
	@echo
	@echo "               Creating symlink..."
	@echo "--------------------------------------------------"
	cd $(LIB_DIR) && ln -fs ~/lib/libSDL2.a
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

debug-linux: $(SRCS)
	$(CC) $(CFLAGS) $^ -L. $(LIBS)

debug-mac:
	echo
