CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=libft.a
SRC= ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJ= $(SRC:.c=.o)

vpath %.c srcs
.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	ar qcs $@ $^

$(OBJ):$(SRC)
	$(CC) -c $^ -Iincludes/ $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(TARGET)

re: fclean all
