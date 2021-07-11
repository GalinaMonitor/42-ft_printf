/*
**@file					ft_parsing_scpr.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief				Functions make string from string, char, proc
**
**@used_functions		{none}
*/

#include "ft_printf.h"

/*
**@brief 			Function makes string from string
**
**@param			arg
**@return			char*
*/

char	*ft_parsing_s(va_list arg)
{
	char	*result;
	char	*temp;
	int		count;

	temp = va_arg(arg, char *);
	if (temp == NULL)
		result = ft_strdup("(null)");
	else
	{
		count = ft_strlen(temp) + 1;
		result = malloc(sizeof(char) * count);
		ft_strlcpy(result, temp, count);
	}
	return (result);
}

/*
**@brief 			Function makes string from char
**
**@param			arg
**@param			flags
**@return			char*
*/

char	*ft_parsing_c(va_list arg, t_flags *flags)
{
	char	*result;

	result = malloc(sizeof(char) * 2);
	*result = va_arg(arg, int);
	if (*result == '\0')
	{
		flags->flags |= FLAG_C_NULL;
		flags->shirina -= 1;
	}
	result[1] = '\0';
	return (result);
}

/*
**@brief 			Function makes string from proc
**
**@param			flags
**@return			char*
*/

char	*ft_parsing_pr(t_flags *flags)
{
	char	*result;

	result = ft_strdup("%");
	if (flags->flags & FLAG_PRS_DIG)
		flags->flags -= FLAG_PRS_DIG;
	if (flags->flags & FLAG_PRS_ARG)
		flags->flags -= FLAG_PRS_ARG;
	return (result);
}
