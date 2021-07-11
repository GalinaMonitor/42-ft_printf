/*
**@file					ft_instruments.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief 				Functions that are used in libftprintf.a multiple times
**
**@used_functions		ft_null_struct, ft_check_if_type, ft_strchr, ft_cmp_memory_length
*/

#include "ft_printf.h"

/*
**@brief 			Function nulls flags structure
**
**@param			flags
*/

void	ft_null_struct(t_flags *flags)
{
	flags->precision = -1;
	flags->flags = 0;
	flags->shirina = 0;
	flags->arg_type = 0;
}

/*
**@brief 			Function, that checks, if there is a type in the string
**
**@param			input
**@return			int
*/

int	ft_check_if_type(const char *input)
{
	int	ind;

	ind = 0;
	while ((!ft_strchr("%dicsufpxXf", input[ind])) && input[ind])
		ind++;
	if (input[ind])
		return (0);
	return (-1);
}

/*
**@brief 			Function, that compare precision and length of the string
**					and allocate appropriate amount of memory for string
**
**@param			input
**@param			res
**@param			len_inp
**@param			flags
**@return			int
*/

int	ft_cmp_memory_length(char *input, char **res, int len_inp, t_flags *flags)
{
	int		size_of_result;

	if (flags->precision > len_inp || (input[0] == '0' && input[1] == '\0'))
	{
		res[0] = malloc(sizeof(char) * (flags->precision + 2));
		size_of_result = flags->precision;
	}
	else
	{
		res[0] = malloc(sizeof(char) * (len_inp + 2));
		size_of_result = len_inp;
	}
	return (size_of_result);
}
