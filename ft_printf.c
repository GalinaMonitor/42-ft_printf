#include "ft_printf.h"

// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (s == NULL)
// 		return ;
// 	write(1, s, ft_strlen(s));
// }
// size_t	ft_strlen(const char *str)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		count++;
// 		str++;
// 	}
// 	return (count);
// }

int	ft_processor(va_list arg, flags *flags)
{
	char	*str;

	str = ft_type_parse(arg, flags);

	if(flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG | FLAG_TYP_F | FLAG_TYP_FMIN))
		str = ft_precision(str, flags);
	if(flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
		str = ft_shirina(str, flags);

	ft_putstr_fd(str, 1);
	flags->count_print += ft_strlen(str);
	free(str);
	return 0;
}

int	ft_check_args_string(const char *input, flags *flags)
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

int ft_parse(va_list arg, const char *input)
{
	flags *flags;
	int check_proc;


	flags = malloc(sizeof(flags));
	flags->count_print = 0;
	flags->precision = -1;
	while(*input)
	{
		if (*input == '%')
		{
			check_proc = ft_check_args_string(++input, flags);
			if (check_proc == 0)
			{
				input = ft_parser_GOD(input, arg, flags);
				ft_processor(arg, flags);
			}
			else if (check_proc == -1)
			{
				free(flags);
				return (-1);
			}
			else
				input+= check_proc;
		}
		else
		{
			ft_putchar_fd(*(input++), 1);
			flags->count_print += 1;
		}
	}
	free(flags);
	return (flags->count_print);
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
