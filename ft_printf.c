#include "ft_printf.h"

const char	*ft_parser_GOD(const char *input)
{
	flags flags;
	flags.flags = 0;
	// while(*input != '%' && *input)
	// {

		if (*input == '-' || *input == '0')
		{
			if (*input == '-')
				flags.flags |= FLAG_FLG_MIN;
			else if (*input == '-')
				flags.flags |= FLAG_FLG_0;
			while(*input == '-' && *input == '0')
				input++;
			input++;
		}

		if (*input >= '0' && *input <= '9')
		{
			flags.shirina = ft_atoi(input);
			while(*input >= '0' && *input <= '9')
				input++;
		}
		else if (*input == '*')
		{
			flags.flags |= FLAG_SHR_ARG;
			input++;
		}

		if (*input == '.')
		{
			if (*input >= '0' && *input <= '9')
			{
				flags.precision = ft_atoi(++input);
				while(*input >= '0' && *input <= '9')
					input++;
			}
			else if (*input == '*')
			{
				flags.flags |= FLAG_PRS_ARG;
				input++;
			}
		}

		if (*input == 'd')
			flags.flags |= FLAG_TYP_D;
		else if (*input == 'i')
			flags.flags |= FLAG_TYP_I;
		else if (*input == 'u')
			flags.flags |= FLAG_TYP_U;
		else if (*input == 'c')
			flags.flags |= FLAG_TYP_C;
		else if (*input == 's')
			flags.flags |= FLAG_TYP_S;
		else if (*input == 'p')
			flags.flags |= FLAG_TYP_P;
		else if (*input == 'x')
			flags.flags |= FLAG_TYP_X;
		else if (*input == 'X')
			flags.flags |= FLAG_TYP_XB;
		else if (*input == '%')
			flags.flags |= FLAG_TYP_PR;
	// }
	printf("%d", flags.flags);
	return (input);
}


ft_parse_args(va_list arg, const char *input)
{
	if (flags.flags & FLAG_SHR_ARG != 0)
	{
		flags.shr = va_arg
	}
}

int ft_parse(va_list arg, const char *input)
{
	while(*input)
	{
		if (*input == '%' && *(input + 1) != '\0')
			input = ft_parser_GOD(++input);
		else
			ft_putchar_fd(*input, 1);
		input++;
	}
	ft_parse_args(arg, input);
	return 1;
}



int ft_printf(const char *input, ...)
{
	va_list arg;
	int count;
	count = 0;
	va_start(arg, input);
	count+= ft_parse(arg, input);
	va_end(arg);
	return 0;
}

int main()
{
	ft_printf("regverv%-5dvervwe", 3);
	return 0;
}
