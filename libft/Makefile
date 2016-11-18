CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
<<<<<<< HEAD
SRC= ft_atoi.c ft_bzero.c ft_intlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_srtcdup.c ft_strcat.c ft_strccnt.c ft_strchr.c ft_strclen.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrealloc.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c
=======
SRC= atoi.c bzero.c intlen.c isalnum.c isalpha.c isascii.c isdigit.c isprint.c \
isspace.c itoa.c memalloc.c memccpy.c memchr.c memcmp.c memcpy.c memdel.c \
memmove.c memset.c putchar.c putchar_fd.c putendl.c putendl_fd.c putnbr.c \
putnbr_fd.c putstr.c putstr_fd.c srtcdup.c strcat.c strccnt.c strchr.c \
strclen.c strclr.c strcmp.c strcpy.c strdel.c strdup.c strequ.c striter.c \
striteri.c strjoin.c strlcat.c strlen.c strmap.c strmapi.c strncat.c\
strncmp.c strncpy.c strnequ.c strnew.c strnstr.c strrchr.c strrealloc.c \
strsplit.c strstr.c strsub.c strtrim.c tolower.c toupper.c lstadd.c lstdel.c\
lstdelone.c lstiter.c lstmap.c lstnew.c
>>>>>>> 1129f6afd2f8aec9658444c92f140ba806ca5bd6
OBJ= $(SRC:.c=.o)
BLANK="\x1B[0m"
DGREEN="\x1B[38;5;28m"
GREEN="\x1B[38;5;40m"
LGREEN="\x1B[38;5;119m"
LLGREEN="\x1B[38;5;193m"
WHITE="\x1B[37m"
DBLUE="\x1B[38;5;19m"
BLUE="\x1B[38;5;21m"
LBLUE="\x1B[38;5;27m"
LLBLUE="\x1B[38;5;81m"

.PHONY: all clean fclean re header it_fabulous

all: $(NAME)

$(NAME): $(OBJ)
	@ar qcs $@ $^

$(OBJ): $(SRC)
	@$(CC) -c $^ $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

header:
	@for i in {1..26} ; do echo $(DGREEN)'<>'$(DBLUE)'-' | tr -d "\n"; done
	@echo $(DGREEN)'<>'
	@echo $(GREEN)'*                                                                            '$(WHITE)'|'$(GREEN)' *'
	@echo $(DBLUE)'|          '$(DGREEN)'/####/         /####/  /########\     /###########/  /###########'$(WHITE)'- -'$(DBLUE)'|'
	@echo $(DBLUE)'|         '$(DGREEN)'/####/         /####/  /#########/    /###########/  /############/'$(WHITE)'|'$(DBLUE)' |'
	@echo $(DBLUE)'|        '$(DGREEN)'/####/         /####/  /####   ##/    /###########/  /############/   '$(DBLUE)'|'
	@echo $(BLUE)'|       '$(GREEN)'/####/         /####/  /####   ##/    /####/             /####/'$(BLUE)'        |'
	@echo $(LBLUE)'|      '$(LGREEN)'/####/         /####/  /#########/    /#########/        /####/'$(LBLUE)'         |'
	@echo $(LLBLUE)'|     '$(LLGREEN)'/####/         /####/  /##########\   /#########/        /####/'$(LLBLUE)'          |'
	@echo $(LBLUE)'|    '$(LGREEN)'/####/         /####/  /####   ####/  /####/             /####/'$(LBLUE)'           |'
	@echo $(BLUE)'|   '$(GREEN)'/###########/  /####/  /####   ####/  /####/             /####/'$(BLUE)'            |'
	@echo $(DBLUE)'| '$(WHITE)'|'$(DGREEN)'/###########/  /####/  /###########/  /####/             /####/'$(DBLUE)'             |'
	@echo $(DBLUE)'|'$(WHITE)'- -'$(DGREEN)'##########/  /####/  /###########/  /####/             /####/'$(DBLUE)'              |'
	@echo $(GREEN)'* '$(WHITE)'|'$(GREEN)'                                                                            *'
	@for i in {1..26} ; do echo $(DGREEN)'<>'$(DBLUE)'-' | tr -d "\n"; done
	@echo $(DGREEN)'<>'
	@echo

it_fabulous: header all
	@echo $(LGREEN)'<'$(BLANK)'==================================='$(LGREEN)'-'$(GREEN)' DONE '$(LGREEN)'-'$(BLANK)\
	'==================================='$(LGREEN)'>'$(BLANK)
	@echo
	@echo '    List of files added to the library :'
	@echo '    ------------------------------------'
	@echo
	@echo $(SRC) | tr ' ' '\n' | sed 's/^/    - /'
	@echo $(LGREEN)'<'$(BLANK)'=============================================================================='$(LGREEN)'>'
