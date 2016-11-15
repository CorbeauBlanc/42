CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=libft.a
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	ar qcs $@ $^

$(OBJ):$(SRC)
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(TARGET)

re: fclean all
