#include "ft_printf.h"

void	ft_null_struct(t_flags *flags)
{
	flags->precision = -1;
	flags->flags = 0;
	flags->shirina = 0;
	flags->arg_type = 0;
}

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
