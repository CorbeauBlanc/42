CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=fillit
SRC=main.c pieces.c files.c list.c exit.c take_error.c search_smaller.c \
ft_lst_size.c move_piece.c ft_puttab.c backtracking.c
OBJ= $(SRC:.c=.o)
MAKE=/usr/bin/make

vpath %.c srcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) libft
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ -Llib -lft
	@echo "Done."
	@echo

$(OBJ): $(SRC)
	@echo "Generating objects..."
	@$(CC) $(CFLAGS) $^ -c -Iincludes
	@echo "Done."

libft:
	@echo "Compiling libft..."
	@$(MAKE) -C lib
	@echo "Done."

clean:
	@echo "Cleaning libft"
	@$(MAKE) clean -C lib
	@echo "Done."
	@echo
	@echo "Removing $(OBJ)"
	@rm -rf $(OBJ)
	@echo "Done."
	@echo

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
	@echo "Done."
	@echo
	@echo "Removing libft"
	@rm -rf lib/libft.a
	@echo "Done."
	@echo

re: fclean all
