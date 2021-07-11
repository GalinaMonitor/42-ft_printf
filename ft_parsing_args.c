#include "ft_printf.h"

int	ft_parse_flags(const char *input, int ind, t_flags *flags)
{
	if (input[ind] == '-')
		flags->flags |= FLAG_FLG_MIN;
	else if (input[ind] == '0')
		flags->flags |= FLAG_FLG_0;
	while (input[ind] == '-' || input[ind] == '0' || input[ind] == '#' \
		|| input[ind] == '+' || input[ind] == ' ')
	{
		if (input[ind] == '-')
			flags->flags |= FLAG_FLG_MIN;
		else if (input[ind] == '+')
			flags->flags |= FLAG_FLG_PLUS;
		else if (input[ind] == '0')
			flags->flags |= FLAG_FLG_0;
		else if (input[ind] == '#')
			flags->flags |= FLAG_FLG_SHARP;
		else if (input[ind] == ' ')
			flags->flags |= FLAG_FLG_SPC;
		if (flags->flags & FLAG_FLG_0 && flags->flags & FLAG_FLG_MIN)
			flags->flags ^= FLAG_FLG_0;
		if (flags->flags & FLAG_FLG_SPC && flags->flags & FLAG_FLG_PLUS)
			flags->flags ^= FLAG_FLG_SPC;
		ind++;
	}
	return (ind);
}

int	ft_parse_shirina(const char *input, int ind, t_flags *flags, va_list arg)
{
	if (input[ind] >= '0' && input[ind] <= '9')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = ft_atoi(input + ind);
		while (input[ind] >= '0' && input[ind] <= '9')
			ind++;
	}
	else if (input[ind] == '*')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = va_arg(arg, int);
		if (flags->shirina < 0)
		{
			flags->flags |= FLAG_FLG_MIN;
			flags->flags ^= FLAG_FLG_0;
			flags->shirina *= -1;
		}
		ind++;
	}
	return (ind);
}

int	ft_parse_precision(const char *input, int ind, t_flags *flags, va_list arg)
{
	ind++;
	if (input[ind] >= '0' && input[ind] <= '9')
	{
		flags->flags |= FLAG_PRS_DIG;
		flags->precision = ft_atoi(input + ind);
		while (input[ind] >= '0' && input[ind] <= '9')
			ind++;
	}
	else if (input[ind] == '*')
	{
		flags->precision = va_arg(arg, int);
		if (flags->precision >= 0)
			flags->flags |= FLAG_PRS_ARG;
		ind++;
	}
	else if (ft_strchr("diucspfxX",  input[ind]))
	{
		flags->flags |= FLAG_PRS_DIG;
		flags->precision = 0;
	}
	return (ind);
}

void	ft_parse_type(char input, t_flags *flags)
{
	if (input == 'd' || input == 'i')
		flags->flags |= FLAG_TYP_D;
	else if (input == 'u')
		flags->flags |= FLAG_TYP_U;
	else if (input == 'c')
		flags->flags |= FLAG_TYP_C;
	else if (input == 's')
		flags->flags |= FLAG_TYP_S;
	else if (input == 'p')
		flags->flags |= FLAG_TYP_P;
	else if (input == 'x')
		flags->flags |= FLAG_TYP_X;
	else if (input == 'X')
		flags->flags |= FLAG_TYP_XB;
	else if (input == 'f')
		flags->flags |= FLAG_TYP_F;
	else if (input == '%')
		flags->flags |= FLAG_TYP_PR;
}
