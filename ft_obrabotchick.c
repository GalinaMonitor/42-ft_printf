#include "ft_printf.h"

char	*ft_precision(char *str, flags *flags)
{
	char	*result;

	if(flags->flags & FLAG_TYP_S)
		result = ft_precision_str(str, flags);
	else if (flags->flags & (FLAG_TYP_D | FLAG_TYP_X | FLAG_TYP_XB | FLAG_TYP_U))
		result = ft_precision_digits(str, flags);
	else if (flags->flags & (FLAG_TYP_F))
		result = ft_precision_float(str, flags);
	return(result);
}

// char	*ft_precision(char *str, flags *flags)
// {
// 	int		size;
// 	int		length;
// 	int		ind;
// 	char	*result;

// 	ind = 0;
// 	length = ft_strlen(str);
// 	if(flags->flags & FLAG_TYP_S)
// 	{
// 		if (flags->precision < length)
// 		{
// 			result = malloc(sizeof(char) * (flags->precision + 1));
// 			size = flags->precision;
// 		}
// 		else
// 		{
// 			result = malloc(sizeof(char) * (length + 1));
// 			size = length;
// 		}
// 	}
// 	if(flags->flags & (FLAG_TYP_D | FLAG_TYP_X | FLAG_TYP_XB | FLAG_TYP_U))
// 	{
// 		if (flags->precision > length || *str == '0')
// 		{
// 			result = malloc(sizeof(char) * (flags->precision + 1));
// 			size = flags->precision;
// 		}
// 		else
// 		{
// 			result = malloc(sizeof(char) * (length + 1));
// 			size = length;
// 		}
// 	}
// 	if((flags->flags & FLAG_FLG_0) || (flags->flags & (FLAG_TYP_D | FLAG_TYP_X | FLAG_TYP_XB | FLAG_TYP_U)))
// 	{
// 		if(*str == '-')
// 		{
// 			result[ind++] = *str;
// 			str++;
// 			length--;
// 		}
// 		while(flags->precision - length > 0)
// 		{
// 			result[ind++] = '0';
// 			length++;
// 			size--;
// 		}
// 	}
// 	while(size-- > 0)
// 	{
// 		result[ind++] = *str;
// 		str++;
// 	}
// 	result[ind] = '\0';
// 	return(result);
// }

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
	{
		if((!(flags->flags & (FLAG_PRS_DIG | FLAG_PRS_ARG)) && (flags->flags & FLAG_FLG_0)) || (flags->flags & (FLAG_TYP_FMIN | FLAG_TYP_F)))
		{
			if(*str == '-')
			{
				result[ind++] = *str;
				str++;
				length--;
			}
			while(spaces-- > 0)
				result[ind++] = '0';
		}
		else
			while(spaces-- > 0)
				result[ind++] = ' ';
	}
	while(length-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	if(flags->flags & FLAG_FLG_MIN)
	{
		while(spaces-- > 0)
			result[ind++] = ' ';
	}
	result[ind] = '\0';
	return(result);
}
