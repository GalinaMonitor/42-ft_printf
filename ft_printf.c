#include "ft_printf.h"

int	ft_processor(va_list arg, flags *flags)
{
	char	*str;

	str = ft_type_parse(arg, flags);

	if(flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG))
		str = ft_precision(str, flags);
	if(flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
		str = ft_shirina(str, flags);
	ft_putstr_fd(str, 1);
	return 0;
}

int ft_parse(va_list arg, const char *input)
{
	flags *flags;

	flags = malloc(sizeof(flags));
	while(*input)
	{
		if (*input == '%' && *(input + 1) != '\0')
		{
			input = ft_parser_GOD(++input, arg, flags);
			ft_processor(arg, flags);
		}
		else
		{
			ft_putchar_fd(*input, 1);
			input++;
		}
	}
	return 1;
}

int ft_printf(const char *input, ...)
{
	va_list arg;
	va_start(arg, input);
	ft_parse(arg, input);
	va_end(arg);
	return 0;
}

int main()
{
	// ft_printf("TEST1_%-*.10d_TEST2_\n", 3, 5);
	// printf("TEST1_%-*.10d_TEST2_\n", 3, 5);
	ft_printf("%08.5d|\n", -5);
 	printf("%08.5d|\n", -5);
	return 0;
}
