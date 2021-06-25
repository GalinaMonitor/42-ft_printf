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
				return 0;
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

ind1 =	printf("01) standart PRINTF : |%p|\n", "salut");
ind2 =	ft_printf("01) my       PRINTF : |%p|\n", "salut");
	printf("01) standart PRINTF : |%d|\n", ind1);
	printf("01) standart PRINTF : |%d|\n", ind2);
	free(tab);
	free(tab2);

}
