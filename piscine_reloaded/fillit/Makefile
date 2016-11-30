CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=fillit
SRC=main.c pieces.c files.c list.c
OBJ= $(SRC:.c=.o)

vpath %.c srcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ -Llib -lft
	@echo "Done."

$(OBJ): $(SRC)
	@echo "Generating objects..."
	@$(CC) $(CFLAGS) $^ -c -Iincludes
	@echo "Done."

clean:
	@echo "removing $(OBJ)"
	@rm -rf $(OBJ)
	@echo

cln_target:
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

fclean: cln_target clean

re: fclean all
