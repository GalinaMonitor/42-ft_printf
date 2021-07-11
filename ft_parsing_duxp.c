#include "ft_printf.h"

char	*ft_parsing_d(va_list arg)
{
	return (ft_itoa(va_arg(arg, int)));
}

char	*ft_parsing_u(va_list arg)
{
	char			*result;
	unsigned int	uns;

	uns = va_arg(arg, unsigned int);
	result = ft_itoa(uns);
	return (result);
}

char	*ft_parsing_x(va_list arg, t_flags *flags)
{
	char	*str;

	str = ft_itoa_base(va_arg(arg, unsigned int), 16, flags);
	return (str);
}

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
