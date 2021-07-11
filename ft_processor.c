#include "ft_printf.h"

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
