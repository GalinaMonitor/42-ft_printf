#include "ft_printf.h"

void	ft_null_struct(s_flags *flags)
{
	flags->precision = -1;
	flags->flags = 0;
	flags->shirina = 0;
	flags->arg_type = 0;
}

int	ft_check_if_type(const char *input)
{
	int ind;
	ind = 0;
	while ((!ft_strchr("%dicsufpxXf", input[ind])) && input[ind])
		ind++;
	if (input[ind])
		return 0;
	return -1;
}

int	ft_cmp_memory_length(char *input, char **result, int length_of_input, s_flags *flags)
{
	int		size_of_result;

	if (flags->precision > length_of_input || *input == '0')
	{
		result[0] = malloc(sizeof(char) * (flags->precision + 2));
		size_of_result = flags->precision;
	}
	else
	{
		result[0] = malloc(sizeof(char) * (length_of_input + 2));
		size_of_result = length_of_input;
	}
	return (size_of_result);
}
