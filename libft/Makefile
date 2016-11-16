CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=libft.a
SRC= atoi.c bzero.c intlen.c isalnum.c isalpha.c isascii.c isdigit.c isprint.c \
isspace.c itoa.c memalloc.c memccpy.c memchr.c memcmp.c memcpy.c memdel.c \
memmove.c memset.c putchar.c putchar_fd.c putendl.c putendl_fd.c putnbr.c \
putnbr_fd.c putstr.c putstr_fd.c srtcdup.c strcat.c strccnt.c strchr.c \
strclen.c strclr.c strcmp.c strcpy.c strdel.c strdup.c strequ.c striter.c \
striteri.c strjoin.c strlcat.c strlen.c strmap.c strmapi.c strncat.c \
strncmp.c strncpy.c strnequ.c strnew.c strnstr.c strrchr.c strrealloc.c \
strsplit.c strstr.c strsub.c strtrim.c tolower.c toupper.c
OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re header it_fabulous

all: $(TARGET)

$(TARGET): $(OBJ)
	@ar qcs $@ $^

$(OBJ): $(SRC)
	@$(CC) -c $^ $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(TARGET)

re: fclean all

header:
	@echo ')>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>\
-<>-<>-<>-<('
	@echo 'v                                                                   \
           v'
	@echo '|          /####/         /####/  /########\     /###########/  /###\
#########/ |'
	@echo '|         /####/         /####/  /#########/    /###########/  /####\
########/  |'
	@echo '|        /####/         /####/  /####   ##/    /###########/  /#####\
#######/   |'
	@echo '|       /####/         /####/  /####   ##/    /####/             /##\
##/        |'
	@echo '|      /####/         /####/  /#########/    /#########/        /###\
#/         |'
	@echo '|     /####/         /####/  /##########\   /#########/        /####\
/          |'
	@echo '|    /####/         /####/  /####   ####/  /####/             /####/\
           |'
	@echo '|   /###########/  /####/  /####   ####/  /####/             /####/ \
           |'
	@echo '|  /###########/  /####/  /###########/  /####/             /####/  \
           |'
	@echo '| /###########/  /####/  /###########/  /####/             /####/   \
           |'
	@echo '^                                                                   \
           ^'
	@echo ')>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>\
-<>-<>-<>-<('

it_fabulous: header all
	@echo
	@echo '<===================================================================\
===========>'
	@echo '                                      DONE'
	@echo '    List of files added to the library :'
	@echo '    ------------------------------------'
	@echo
	@echo $(SRC) | tr ' ' '\n' | sed 's/^/    - /'
	@echo '<===================================================================\
===========>'
