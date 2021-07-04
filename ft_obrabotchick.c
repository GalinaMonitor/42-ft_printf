#include "ft_printf.h"

char	*ft_precision(char *str, s_flags *flags)
{
	char	*result;

	if(flags->flags & FLAG_TYP_S)
		result = ft_precision_str(str, flags);
	else if (flags->flags & (FLAG_TYP_D | FLAG_TYP_X | FLAG_TYP_XB | FLAG_TYP_U))
		result = ft_precision_digits(str, flags);
	else if (flags->flags & (FLAG_TYP_F))
		result = ft_precision_float(str, flags);
	else
		return(str);
	free(str);
	return(result);
}

char	*ft_shirina(char *str, s_flags *flags)
{
	int		spaces;
	int		length;
	int		ind;
	int		ind2;
	char	*result;

	ind = 0;
	ind2 = 0;
	length = ft_strlen(str);
	spaces = flags->shirina - length;
	if (spaces < 0)
		spaces = 0;
	result = malloc(sizeof(char) * (length + spaces + 1));

	if(!(flags->flags & FLAG_FLG_MIN))
	{
		if((!(flags->flags & (FLAG_PRS_DIG | FLAG_PRS_ARG)) && (flags->flags & FLAG_FLG_0)) || (flags->flags & (FLAG_TYP_FMIN | FLAG_TYP_F)))
		{
			if(str[ind2] == '-')
			{
				result[ind++] = str[ind2];
				ind2++;;
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
		result[ind++] = str[ind2];
		ind2++;
	}
	if(flags->flags & FLAG_FLG_MIN)
	{
		while(spaces-- > 0)
			result[ind++] = ' ';
	}
	result[ind] = '\0';
	if(str)
		free(str);
	return(result);
}
