NAME = libft.a

NAME_PRINTF = ft_printf

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT_LIST = ft_memset.c\
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

# LIBFT_LIST_B = ft_lstnew.c\
# 	ft_lstadd_front.c\
# 	ft_lstsize.c\
# 	ft_lstlast.c\
# 	ft_lstadd_back.c\
# 	ft_lstclear.c\
# 	ft_lstdelone.c\
# 	ft_lstiter.c\
# 	ft_lstmap.c\

SOURCES_LIST_PRINTF = ft_printf.c\
	ft_obrabotchick.c\
	ft_parsing.c\

HEADER_PRINTF = ft_printf.h

LIBFT_DIR = libft/

LIBFT_FUNCS = $(addprefix $(LIBFT_DIR),$(LIBFT_LIST))


OBJECTS = $(patsubst %.c, %.o, $(LIBFT_FUNCS))


D_FILES = $(patsubst %.c, %.d, $(LIBFT_FUNCS))

all: $(NAME) $(SOURCES_LIST_PRINTF) $(HEADER_PRINTF)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $?
	@echo "libft.a is ready to use"
	$(CC) $(FLAGS) $(SOURCES_LIST_PRINTF) $(NAME) -o $(NAME_PRINTF)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

bonus: $(OBJECTS_B)
	@ar rcs $(NAME) $?
	@echo "Libft Bonus Done!"

clean:
	@rm -f $(OBJECTS_B) $(OBJECTS) $(D_FILES)
	@echo "Annihilation success"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : re all fclean clean bonus
