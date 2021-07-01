#include "ft_printf.h"

char	*ft_type_parse(va_list arg, flags *flags)
{
	char *str;
	unsigned int uns;

	if (flags->flags & FLAG_TYP_D)
		str = ft_itoa(va_arg(arg, int));

	if (flags->flags & FLAG_TYP_U)
	{
		uns = va_arg(arg, unsigned int);
		if (uns < 0)
		{
			uns+= 4294967295 - uns;
		}
		str = ft_itoa(uns);
	}


	if (flags->flags & FLAG_TYP_S)
	{
		str = va_arg(arg, char *);
		if (str == NULL)
		{
			str = ft_strdup("(null)");
		}
	}

	if (flags->flags & FLAG_TYP_C)
	{
		str = malloc(sizeof(char) * 2);
		*str = va_arg(arg, int);
		if (*str == '\0')
			flags->shirina-= 1;
		str++;
		*str = '\0';
		str--;
	}

	if (flags->flags & FLAG_TYP_X || flags->flags & FLAG_TYP_XB)
		str = ft_itoa_base16(va_arg(arg, unsigned int), flags);

	if (flags->flags & FLAG_TYP_P)
	{
		str = ft_itoa_base16(va_arg(arg, unsigned long), flags);
		str = ft_strjoin("0x", str);
	}

	if (flags->flags & FLAG_TYP_F)
	{
		str = ft_itoa_base16(va_arg(arg, unsigned long), flags);
		str = ft_strjoin("0x", str);
	}


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
		while(*input == '-' || *input == '0') ///yrbvkwr,hbvliwekvjbwen
			input++;
		if (*input == '-' || *input == '0')
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
		else if (ft_strchr("diucspxX", *input))
		{
			flags->flags |= FLAG_PRS_DIG;
			flags->precision = 0;
		}
	}
	if (*input == 'd' || *input == 'i')
		flags->flags |= FLAG_TYP_D;
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
	else if (*input == 'f')
		flags->flags |= FLAG_TYP_D;
	return (++input);
}
