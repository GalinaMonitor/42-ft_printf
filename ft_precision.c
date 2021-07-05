#include "ft_printf.h"

char	*ft_precision_str(char *input, s_flags *flags)
{
	int		size_of_result;
	int		length_of_input;
	int		ind;
	char	*result;

	ind = 0;
	length_of_input = ft_strlen(input);
	if (flags->precision < length_of_input)
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size_of_result = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (length_of_input + 1));
		size_of_result = length_of_input;
	}
	while(size_of_result-- > 0)
	{
		result[ind++] = *input;
		input++;
	}
	result[ind] = '\0';
	return(result);
}

char	*ft_precision_digits(char *input, s_flags *flags)
{
	int		size_of_result;
	int		length_of_input;
	int		ind;
	char	*result;

	ind = 0;
	length_of_input = ft_strlen(input);
	size_of_result = ft_cmp_memory_length(input, &result, length_of_input, flags);
	if(*input == '-')
	{
		result[ind++] = *(input++);
		length_of_input--;
	}
	while(flags->precision - length_of_input > 0)
	{
		result[ind++] = '0';
		length_of_input++;
		size_of_result--;
	}
	while(size_of_result-- > 0)
		result[ind++] = *(input++);
	result[ind] = '\0';
	return(result);
}

char	*ft_precision(char *input, s_flags *flags)
{
	char	*result;

	if(flags->flags & FLAG_TYP_S)
		result = ft_precision_str(input, flags);
	else if (flags->flags & (FLAG_TYP_D | FLAG_TYP_X | FLAG_TYP_XB | FLAG_TYP_U))
		result = ft_precision_digits(input, flags);
	else if (flags->flags & (FLAG_TYP_F))
		result = ft_precision_float(input, flags);
	else
		return(input);
	free(input);
	return(result);
}
