/*
**@file					ft_shirina.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-12
**
**@brief 				Function reallocates result-string and
**						applies width settings on string
**
**@used_functions		ft_shirina, ft_strlen
*/

#include "ft_printf.h"

char	*ft_shirina(char *str, t_flags *flags)
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
		if((!(flags->flags & (FLAG_PRS_DIG | FLAG_PRS_ARG)) && (flags->flags & FLAG_FLG_0)))
		{
			if(str[ind2] == '-')
			{
				result[ind++] = str[ind2++];
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
		result[ind++] = str[ind2++];
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
