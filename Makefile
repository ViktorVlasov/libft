NAME = libft.a
OBJ_FILES = ft_atoi.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_strnstr.o ft_tolower.o ft_toupper.o ft_isdigit.o ft_isalnum.o ft_isprint.o ft_isascii.o ft_isalpha.o ft_calloc.o ft_strdup.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_strmapi.o ft_itoa.o
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

so:
	$(CC) -shared -o libft.so $(OBJ_FILES)
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re