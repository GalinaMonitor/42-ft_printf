NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

DIR_PRINTF = ./

DIR_LIBFT = libft/

HEADER = ft_printf.h

DIR_LIBFT = libft/libft/
LIBFT = libft/libft/libft.a

SOURCES_LIST_PRINTF = ft_printf.c\
	ft_parsing.c\
	ft_itoa_base.c\
	ft_precision.c\
	ft_instruments.c\
	ft_processor.c\
	ft_parsing_scpr.c\
	ft_parsing_duxp.c\
	ft_parsing_args.c\
	ft_shirina.c\
	ft_long_math.c\
	ft_parsing_float.c\
	ft_precision_float.c\

FUNCS = $(addprefix $(DIR_PRINTF), $(SOURCES_LIST_PRINTF))

OBJECTS = $(patsubst %.c, %.o, $(FUNCS))

all: $(NAME)
$(NAME): $(LIBFT) $(OBJECTS)
	@ar rcs $(NAME) $?
	@echo "libftprintf.a is ready to use"

%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@ -I ./libft

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT)

bonus: $(OBJECTS)
	@ar rcs $(NAME) $?
	@echo "libftprintf.a with bonuses is ready to use"

clean:
	@$(MAKE) clean -C $(DIR_LIBFT)
	@rm -f $(OBJECTS)
	@echo "Annihilation success"

fclean: clean
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY : all re fclean clean bonus
