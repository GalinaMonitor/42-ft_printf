/*
**@file					ft_parsing_args.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief 				Functions are used to parse precision, width,
**						flags and types of the arg-string
**
**@used_functions		ft_parse_flags, ft_parse_shirina, ft_atoi,
**						ft_parse_precision, ft_strchr, ft_parse_type
*/

#include "ft_printf.h"

/*
**@brief 			Function parse flags of the string
**
**@param			input
**@param			ind
**@param			flags
**@return			int
*/

int	ft_parse_flags(const char *input, int ind, t_flags *flags)
{
	if (input[ind] == '-')
		flags->flags |= FLAG_FLG_MIN;
	else if (input[ind] == '0')
		flags->flags |= FLAG_FLG_0;
	while (input[ind] == '-' || input[ind] == '0' || input[ind] == '#' \
		|| input[ind] == '+' || input[ind] == ' ')
	{
		if (input[ind] == '-')
			flags->flags |= FLAG_FLG_MIN;
		else if (input[ind] == '+')
			flags->flags |= FLAG_FLG_PLUS;
		else if (input[ind] == '0')
			flags->flags |= FLAG_FLG_0;
		else if (input[ind] == '#')
			flags->flags |= FLAG_FLG_SHARP;
		else if (input[ind] == ' ')
			flags->flags |= FLAG_FLG_SPC;
		if (flags->flags & FLAG_FLG_0 && flags->flags & FLAG_FLG_MIN)
			flags->flags ^= FLAG_FLG_0;
		if (flags->flags & FLAG_FLG_SPC && flags->flags & FLAG_FLG_PLUS)
			flags->flags ^= FLAG_FLG_SPC;
		ind++;
	}
	return (ind);
}

/*
**@brief 			Function parse width of the string
**
**@param			input
**@param			ind
**@param			flags
**@param			arg
**@return			int
*/

int	ft_parse_shirina(const char *input, int ind, t_flags *flags, va_list arg)
{
	if (input[ind] >= '0' && input[ind] <= '9')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = ft_atoi(input + ind);
		while (input[ind] >= '0' && input[ind] <= '9')
			ind++;
	}
	else if (input[ind] == '*')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = va_arg(arg, int);
		if (flags->shirina < 0)
		{
			flags->flags |= FLAG_FLG_MIN;
			flags->flags ^= FLAG_FLG_0;
			flags->shirina *= -1;
		}
		ind++;
	}
	return (ind);
}

/*
**@brief 			Function parse precision of the string
**
**@param			input
**@param			ind
**@param			flags
**@param			arg
**@return			int
*/

int	ft_parse_precision(const char *input, int ind, t_flags *flags, va_list arg)
{
	ind++;
	if (input[ind] >= '0' && input[ind] <= '9')
	{
		flags->flags |= FLAG_PRS_DIG;
		flags->precision = ft_atoi(input + ind);
		while (input[ind] >= '0' && input[ind] <= '9')
			ind++;
	}
	else if (input[ind] == '*')
	{
		flags->precision = va_arg(arg, int);
		if (flags->precision >= 0)
			flags->flags |= FLAG_PRS_ARG;
		ind++;
	}
	else if (ft_strchr("diucsfpxX", input[ind]))
	{
		flags->flags |= FLAG_PRS_DIG;
		flags->precision = 0;
	}
	return (ind);
}

/*
**@brief 			Function parse type of the string
**
**@param			input
**@param			flags
*/

void	ft_parse_type(char input, t_flags *flags)
{
	if (input == 'd' || input == 'i')
		flags->flags |= FLAG_TYP_D;
	else if (input == 'u')
		flags->flags |= FLAG_TYP_U;
	else if (input == 'c')
		flags->flags |= FLAG_TYP_C;
	else if (input == 's')
		flags->flags |= FLAG_TYP_S;
	else if (input == 'p')
		flags->flags |= FLAG_TYP_P;
	else if (input == 'x')
		flags->flags |= FLAG_TYP_X;
	else if (input == 'X')
		flags->flags |= FLAG_TYP_XB;
		else if (input == 'f')
		flags->flags |= FLAG_TYP_F;
	else if (input == '%')
		flags->flags |= FLAG_TYP_PR;
}
