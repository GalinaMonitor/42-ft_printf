#include "ft_printf.h"

char	*ft_precision_str(char *str, flags *flags)
{
	int		size;
	int		length;
	int		ind;
	char	*result;

	ind = 0;
	length = ft_strlen(str);
	if (flags->precision < length)
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (length + 1));
		size = length;
	}
	while(size-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	result[ind] = '\0';
	return(result);
}

char	*ft_precision_digits(char *str, flags *flags)
{
	int		size;
	int		length;
	int		ind;
	char	*result;

	ind = 0;
	length = ft_strlen(str);
	if (flags->precision > length || *str == '0')
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (length + 1));
		size = length;
	}

	if(*str == '-')
	{
		result[ind++] = *str;
		str++;
		length--;
	}
	while(flags->precision - length > 0)
	{
		result[ind++] = '0';
		length++;
		size--;
	}
	while(size-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	result[ind] = '\0';
	return(result);
}
