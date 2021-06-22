#include "ft_printf.h"

char	*ft_shirina(char *str, flags *flags)
{
	int		spaces;
	int		length;
	int		ind;
	char	*result;

	ind = 0;
	length = ft_strlen(str);
	spaces = flags->shirina - ft_strlen(str);
	result = malloc(sizeof(char) * (length + spaces + 1));
	if(!(flags->flags & FLAG_FLG_MIN))
		while(spaces-- > 0)
			result[ind++] = ' ';
	while(length-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	if(flags->flags & FLAG_FLG_MIN)
		while(spaces-- > 0)
			result[ind++] = ' ';
	result[ind] = '\0';
	return(result);
}

char	*ft_precision(char *str, flags *flags)
{
	int		size;
	int		length;
	int		ind;
	char	*result;

	ind = 0;
	length = ft_strlen(str);
	if(flags->precision < length || flags->flags & FLAG_FLG_0)
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (length + 1));
		size = length;
	}
	if(flags->flags & FLAG_FLG_0)
	{
		while(flags->precision - length > 0)
		{
			result[ind++] = '0';
			length++;
			size--;
		}
	}
	while(size-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	result[ind] = '\0';
	return(result);
}
