/*
**@file					ft_parsing_duxp.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief				Functions make string from digits, unsigned,
**						hexadecimal and pointers
**
**@used_functions		ft_parsing_d, ft_itoa, ft_parsing_u, ft_parsing_x,
**						ft_itoa_base, ft_parsing_p, ft_strdup, ft_strjoin
*/

#include "ft_printf.h"

/*
**@brief 			Function makes string from integer
**
**@param			arg
**@return			char*
*/

char	*ft_parsing_d(va_list arg)
{
	return (ft_itoa(va_arg(arg, int)));
}

/*
**@brief 			Function makes string from unsigned
**
**@param			arg
**@return			char*
*/

char	*ft_parsing_u(va_list arg)
{
	char			*result;
	unsigned int	uns;

	uns = va_arg(arg, unsigned int);
	result = ft_itoa(uns);
	return (result);
}

/*
**@brief 			Function makes string from hexadecimal number
**
**@param			arg
**@param			flags
**@return			char*
*/

char	*ft_parsing_x(va_list arg, t_flags *flags)
{
	char	*str;

	str = ft_itoa_base(va_arg(arg, unsigned int), 16, flags);
	return (str);
}

/*
**@brief 			Function makes string from pointer
**
**@param			arg
**@param			flags
**@return			char*
*/

char	*ft_parsing_p(va_list arg, t_flags *flags)
{
	char	*result;
	char	*temp;

	temp = ft_itoa_base(va_arg(arg, unsigned long long), 16, flags);
	if ((temp[1]) == '\0' && flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG))
		result = ft_strdup("0x");
	else
		result = ft_strjoin("0x", temp);
	free(temp);
	return (result);
}
