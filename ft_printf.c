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
	flags->count_print += ft_strlen(str);
	return 0;
}

int	ft_check_args_string(const char *input, flags *flags)
{
	int ind;
	ind = 0;
	while ((!ft_strchr("%dicsupxX", input[ind])) && input[ind])
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
				return (-1);
			else
				input+= check_proc;
		}
		else
		{
			ft_putchar_fd(*(input++), 1);
			flags->count_print += 1;
		}
	}
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

int main()
{
	int	*tab = malloc(sizeof(int) * 10);
	int	*tab2 = malloc(0);

	int ind1;
	int ind2;

	printf("07) standart PRINTF : |%c|\n", '\0');
	ft_printf("07) my       PRINTF : |%c|\n", '\0');
	printf("08) standart PRINTF : |%5c|\n", '\0');
	ft_printf("08) my       PRINTF : |%5c|\n", '\0');
	printf("09) standart PRINTF : |%-5c|\n", '\0');
	ft_printf("09) my       PRINTF : |%-5c|\n", '\0');
	printf("10) standart PRINTF : |%1c|\n", '\0');
	ft_printf("10} my       PRINTF : |%1c|\n", '\0');


}
