NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

DIR_PRINTF = ./

DIR_LIBFT = libft/

SOURCES_LIST_PRINTF = ft_printf.c\
	ft_obrabotchick.c\
	ft_parsing.c\
	ft_itoa_base.c\
	ft_precision.c\
	ft_long_math.c\
	ft_parsing_float.c\
	ft_instruments.c

SOURCES_LIST_LIBFT = ft_memset.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strmapi.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\

PRINTF_FUNCS = $(addprefix $(DIR_PRINTF), $(SOURCES_LIST_PRINTF))
LIBFT_FUNCS = $(addprefix $(DIR_LIBFT), $(SOURCES_LIST_LIBFT))

FUNCS = $(PRINTF_FUNCS) $(LIBFT_FUNCS)

OBJECTS = $(patsubst %.c, %.o, $(FUNCS))

all: $(NAME)
$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $?
	@echo "libftprintf.a is ready to use"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I ./

clean:
	@rm -f $(OBJECTS)
	@echo "Annihilation success"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all re fclean clean
