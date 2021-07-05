#include "ft_printf.h"

void	ft_print_end_of_string(char	*str, s_flags *flags)
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

int	ft_processor(va_list arg, s_flags *flags)
{
	char	*str;

	str = ft_type_parse(arg, flags);

	if(flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG | FLAG_TYP_F | FLAG_TYP_FMIN))
		str = ft_precision(str, flags);
	if(flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
		str = ft_shirina(str, flags);
	if (flags->flags & FLAG_C_NULL)
		ft_print_end_of_string(str, flags);
	else
		ft_putstr_fd(str, 1);
	flags->count_print += ft_strlen(str);
	if (str)
		free(str);
	return 0;
}
