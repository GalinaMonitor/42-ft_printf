#include "ft_printf.h"

int	ft_check_type_and_parse(const char *input, va_list arg, t_flags *flags)
{
	int	check_args;
	int	move_str;

	check_args = ft_check_if_type(++input);
	if (check_args == 0)
	{
		move_str = 1 + ft_parser_god(input, arg, flags);
		ft_processor(arg, flags);
		return (move_str);
	}
	else if (check_args == -1)
		return (-1);
	else
		return (check_args);
}

int	ft_printtrash_and_parse(va_list arg, t_flags *flags, const char *input)
{
	int	move_str;

	while (*input)
	{
		if (*input == '%')
		{
			ft_null_struct(flags);
			move_str = ft_check_type_and_parse(input, arg, flags);
			if (move_str >= 0)
				input += move_str;
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(*(input++), 1);
			flags->count_print += 1;
		}
	}
	return (0);
}

int	ft_parse(va_list arg, const char *input)
{
	t_flags	flags;
	int		count_print;

	ft_null_struct(&flags);
	flags.count_print = 0;
	if (ft_printtrash_and_parse(arg, &flags, input) == -1)
		return (0);
	count_print = flags.count_print;
	return (count_print);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		count_print;

	va_start(arg, input);
	count_print = ft_parse(arg, input);
	va_end(arg);
	return (count_print);
}
