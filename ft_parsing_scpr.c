#include "ft_printf.h"

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
