#include "ft_printf.h"

char	*ft_type_parse(va_list arg, flags *flags)
{
	char *str;

	if (flags->flags & FLAG_TYP_D)
	{
		str = ft_itoa(va_arg(arg, int));
	}
	// else if (*input == 'i')
	// 	flags->flags |= FLAG_TYP_I;
	// else if (*input == 'u')
	// 	flags->flags |= FLAG_TYP_U;
	// else if (*input == 'c')
	// 	flags->flags |= FLAG_TYP_C;
	// else if (*input == 's')
	// 	flags->flags |= FLAG_TYP_S;
	// else if (*input == 'p')
	// 	flags->flags |= FLAG_TYP_P;
	// else if (*input == 'x')
	// 	flags->flags |= FLAG_TYP_X;
	// else if (*input == 'X')
	// 	flags->flags |= FLAG_TYP_XB;
	// else if (*input == '%')
	// 	flags->flags |= FLAG_TYP_PR;
	return str;
}


const char	*ft_parser_GOD(const char *input, va_list arg, flags *flags)
{
	flags->flags = 0;
	if (*input == '-' || *input == '0')
	{
		if (*input == '-')
			flags->flags |= FLAG_FLG_MIN;
		else if (*input == '0')
			flags->flags |= FLAG_FLG_0;
		while(*input == '-' && *input == '0')
			input++;
		input++;
	}
	if (*input >= '0' && *input <= '9')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = ft_atoi(input);
		while(*input >= '0' && *input <= '9')
			input++;
	}
	else if (*input == '*')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = va_arg(arg, int);
		input++;
	}
	if (*input == '.')
	{
		input++;
		if (*input >= '0' && *input <= '9')
		{
			flags->flags |= FLAG_PRS_DIG;
			flags->precision = ft_atoi(input);
			while(*input >= '0' && *input <= '9')
				input++;
		}
		else if (*input == '*')
		{
			flags->flags |= FLAG_PRS_ARG;
			flags->precision = va_arg(arg, int);
			input++;
		}
	}
	if (*input == 'd')
		flags->flags |= FLAG_TYP_D;
	else if (*input == 'i')
		flags->flags |= FLAG_TYP_I;
	else if (*input == 'u')
		flags->flags |= FLAG_TYP_U;
	else if (*input == 'c')
		flags->flags |= FLAG_TYP_C;
	else if (*input == 's')
		flags->flags |= FLAG_TYP_S;
	else if (*input == 'p')
		flags->flags |= FLAG_TYP_P;
	else if (*input == 'x')
		flags->flags |= FLAG_TYP_X;
	else if (*input == 'X')
		flags->flags |= FLAG_TYP_XB;
	else if (*input == '%')
		flags->flags |= FLAG_TYP_PR;
	// printf("%d", flags->flags & FLAG_SHR_DIG);
	return (++input);
}
