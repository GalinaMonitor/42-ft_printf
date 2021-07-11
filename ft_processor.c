/*
**@file					ft_processor.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief				Main logical distribution center
**
**@used_functions		ft_print_end_of_string, ft_putchar_fd
**						ft_putstr_fd, ft_processor, ft_type_parse,
**						ft_precision, ft_shirina, ft_strjoin, ft_strlen
*/

#include "ft_printf.h"

/*
**@brief 			Function prints \0
**
**@param			str
**@param			flags
*/

void	ft_print_end_of_string(char	*str, t_flags *flags)
{
	if (flags->flags & FLAG_FLG_MIN)
	{
		ft_putchar_fd('\0', 1);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\0', 1);
	}
	flags->flags ^= FLAG_C_NULL;
	flags->count_print += 1;
}

/*
**@brief 			Main logical distribution center
**
**@param			arg
**@param			flags
**@return			int
*/

int	ft_processor(va_list arg, t_flags *flags)
{
	char	*str;

	str = ft_type_parse(arg, flags);
	if (flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG | FLAG_TYP_F | FLAG_TYP_FMIN))
		str = ft_precision(str, flags);
	if (flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
		str = ft_shirina(str, flags);
	if (flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
	{
		if (flags->flags & FLAG_FLG_SPC && str[0] != '-')
			str = ft_strjoin(" ", str);
		if (flags->flags & FLAG_FLG_PLUS && str[0] != '-')
			str = ft_strjoin("+", str);
	}
	if (flags->flags & FLAG_PRS)
		if (!(flags->flags & FLAG_FLG_SHARP))
		{
			if (flags->flags & FLAG_TYP_X)
				str = ft_strjoin("0x", str);
			if (flags->flags & FLAG_TYP_XB)
				str = ft_strjoin("0X", str);
		}
	if (flags->flags & FLAG_C_NULL)
		ft_print_end_of_string(str, flags);
	else
		ft_putstr_fd(str, 1);
	flags->count_print += ft_strlen(str);
	if (str)
		free(str);
	return (0);
}
