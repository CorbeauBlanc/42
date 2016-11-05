CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=ft_display_file
SRC= main.c
OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJ):$(SRC)
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(TARGET)

re: fclean all
