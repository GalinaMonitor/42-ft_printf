/*
**@file					ft_printf.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief 				Main function, main aim is va-initialize
**						and check of income-string
**
**@used_functions		ft_check_type_and_parse, ft_check_if_type, ft_parser_god,
**						ft_processor, ft_printtrash_and_parse, ft_null_struct,
**						ft_putchar_fd, ft_parse, ft_printf
*/

#include "ft_printf.h"

/*
**@brief 			Function checks, if there is a type in the arg-string
**
**@param			input
**@param			arg
**@param			flags
**@return			int
*/

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

/*
**@brief 			Function makes a loop for parsing multiple types and print trash
**
**@param			arg
**@param			flags
**@param			input
**@return			int
*/

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

/*
**@brief 			Function initialize flag-struct and sends va_list to the next function
**
**@param			arg
**@param			input
**@return			int
*/

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

/*
**@brief 			Starting function and va_list initialize
**
**@param			input
**@param			...
**@return			int
*/

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		count_print;

	va_start(arg, input);
	count_print = ft_parse(arg, input);
	va_end(arg);
	return (count_print);
}
