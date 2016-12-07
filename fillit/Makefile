CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=fillit
SRC=main.c pieces.c files.c list.c exit.c take_error.c search_smaller.c \
ft_lst_size.c move_piece.c ft_puttab.c
OBJ= $(SRC:.c=.o)
MAKE=/usr/bin/make

vpath %.c srcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
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
	@echo "removing $(OBJ)"
	@rm -rf $(OBJ)
	@echo "Done."
	@echo

cln_target:
	@echo "removing $(NAME)"
	@rm -rf $(NAME)
	@echo "Done."

fclean: cln_target clean

re: fclean all
