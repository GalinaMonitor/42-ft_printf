#include "ft_printf.h"

int	ft_processor(va_list arg, s_flags *flags)
{
	char	*str;

	str = ft_type_parse(arg, flags);

	if(flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG | FLAG_TYP_F | FLAG_TYP_FMIN))
		str = ft_precision(str, flags);
	if(flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
		str = ft_shirina(str, flags);

	ft_putstr_fd(str, 1);
	flags->count_print += ft_strlen(str);
	if (str)
		free(str);
	return 0;
}

int	ft_check_args_string(const char *input, s_flags *flags)
{
	int ind;
	ind = 0;
	while ((!ft_strchr("%dicsufpxXf", input[ind])) && input[ind])
		ind++;
	if (input[ind] == '%')
	{
		ft_putchar_fd(input[ind], 1);
		flags->count_print += 1;
		return ++ind;
	}
	if (input[ind])
		return 0;
	return -1;
}

int ft_check_and_parse(const char *input, va_list arg, s_flags *flags)
{
	int check_args;
	int move_str;

	check_args = ft_check_args_string(++input, flags);
	if (check_args == 0)
	{
		move_str = ft_parser_GOD(input, arg, flags);
		ft_processor(arg, flags);
		return (move_str);
	}
	else if (check_args == -1)
	{
		free(flags);
		return (-2);
	}
	else
		return(check_args);
}

int ft_parse(va_list arg, const char *input)
{
	s_flags *flags;
	int move_str;
	int count_print;

	move_str = 1;
	flags = (s_flags *)malloc(sizeof(s_flags));
	if (flags == NULL)
		return (-1);
	flags->count_print = 0;
	flags->precision = -1;
	while(*input)
	{
		if (*input == '%')
		{
			move_str += ft_check_and_parse(input, arg, flags);
			if (move_str >= 0)
				input+= move_str;
			else
				return (-1);
			move_str = 1;
		}
		else
		{
			ft_putchar_fd(*(input++), 1);
			flags->count_print += 1;
		}
	}
	count_print = flags->count_print;
	free(flags);
	return (count_print);
}

int ft_printf(const char *input, ...)
{
	va_list arg;
	int count_print;
	va_start(arg, input);
	count_print = ft_parse(arg, input);
	va_end(arg);
	return (count_print);
}
