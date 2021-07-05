#include "ft_printf.h"

char	*ft_type_parse(va_list arg, s_flags *flags)
{
	char *result;

	result = NULL;
	if (flags->flags & FLAG_TYP_D)
		result = ft_parsing_d(arg, flags);
	else if (flags->flags & FLAG_TYP_U)
		result = ft_parsing_u(arg, flags);
	else if (flags->flags & FLAG_TYP_X || flags->flags & FLAG_TYP_XB)
		result = ft_parsing_x(arg, flags);
	else if (flags->flags & FLAG_TYP_P)
		result = ft_parsing_p(arg, flags);
	else if (flags->flags & FLAG_TYP_S)
		result = ft_parsing_s(arg, flags);
	else if (flags->flags & FLAG_TYP_C)
		result = ft_parsing_c(arg, flags);
	else if (flags->flags & FLAG_TYP_PR)
		result = ft_parsing_pr(arg, flags);
	else if (flags->flags & FLAG_TYP_F)
		result = ft_parsing_float(arg, flags);
	return (result);
}

int	ft_parser_GOD(const char *input, va_list arg, s_flags *flags)
{
	int ind;

	ind = 0;
	flags->flags = 0;
	if (input[ind] == '-' ||  input[ind] == '0')
		ind = ft_parse_flags(input, ind, flags);
	if ((input[ind] >= '0' &&  input[ind] <= '9') || input[ind] == '*')
		ind = ft_parse_shirina(input, ind, flags, arg);
	if ( input[ind] == '.')
		ind = ft_parse_precision(input, ind, flags, arg);
	ft_parse_type(input[ind], flags);
	return (++ind);
}
