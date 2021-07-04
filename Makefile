NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SOURCES_LIST_PRINTF = ft_printf.c\
	ft_obrabotchick.c\
	ft_parsing.c\
	ft_itoa_base.c\
	ft_precision.c\
	ft_parsing_float.c\
	ft_long_math.c

HEADER_PRINTF = ft_printf.h

LIBFT_DIR = libft/

PRINTF_FUNCS = $(SOURCES_LIST_PRINTF)

OBJECTS = $(patsubst %.c, %.o, $(PRINTF_FUNCS))

all: $(NAME)
$(NAME): $(OBJECTS)
	@$(MAKE) -C ./libft
	@cp $(LIBFT) ./$(NAME)
	@ar rcs $(NAME) $?
	@echo "libftprintf.a is ready to use"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I ./

# bonus: $(OBJECTS_B)
# 	ar rcs $(NAME) $?
# 	echo "Libft Bonus Done!"

clean:
	@$(MAKE) -C ./libft clean
	@rm -f $(OBJECTS)
	@echo "Annihilation success"

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY : re all fclean clean
