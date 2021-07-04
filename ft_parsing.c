#include "ft_printf.h"

char	*ft_type_parse(va_list arg, s_flags *flags)
{
	char *temp;

	char *str;
	unsigned int uns;
	int count;

	if (flags->flags & FLAG_TYP_D)
		str = ft_itoa(va_arg(arg, int));
	else if (flags->flags & FLAG_TYP_U)
	{
		uns = va_arg(arg, unsigned int);
		// if (uns < 0)
		// {
		// 	uns+= 4294967295 - uns;
		// }
		str = ft_itoa(uns);
	}


	else if (flags->flags & FLAG_TYP_S)
	{
		temp = va_arg(arg, char *);

		if (temp == NULL)
		{
			str = ft_strdup("(null)");
		}
		else
		{
			count = ft_strlen(temp) + 1;
			str = malloc(sizeof(char) * count);
			ft_strlcpy(str, temp, count);
		}
	}

	else if (flags->flags & FLAG_TYP_C)
	{
		str = malloc(sizeof(char) * 2);
		*str = va_arg(arg, int);
		if (*str == '\0')
			flags->shirina-= 1;
		str++;
		*str = '\0';
		str--;
	}

	else if (flags->flags & FLAG_TYP_X || flags->flags & FLAG_TYP_XB)
		str = ft_itoa_base(va_arg(arg, unsigned int), 16, flags);

	else if (flags->flags & FLAG_TYP_P)
	{
		temp = ft_itoa_base(va_arg(arg, unsigned long), 16, flags);
		str = ft_strjoin("0x", temp);
		free(temp);
	}

	else if (flags->flags & FLAG_TYP_F)
	{
		long double ch = va_arg(arg, long double);
		str = ft_parsing_float(ch, flags);
	}
	return str;
}


int	ft_parser_GOD(const char *input, va_list arg, s_flags *flags)
{
	int ind;

	ind = 0;
	flags->flags = 0;
	if ( input[ind] == '-' ||  input[ind] == '0')
	{
		if ( input[ind] == '-')
			flags->flags |= FLAG_FLG_MIN;
		else if ( input[ind] == '0')
			flags->flags |= FLAG_FLG_0;
		while( input[ind] == '-' ||  input[ind] == '0') ///yrbvkwr,hbvliwekvjbwen
		{
			if ( input[ind] == '-' && (flags->flags & FLAG_FLG_0))
			{
				flags->flags |= FLAG_FLG_MIN;
				flags->flags ^= FLAG_FLG_0;
			}
			ind++;
		}
		if ( input[ind] == '-' ||  input[ind] == '0')
			ind++;
	}
	if ( input[ind] >= '0' &&  input[ind] <= '9')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = ft_atoi(input + ind);
		while( input[ind] >= '0' &&  input[ind] <= '9')
			ind++;
	}
	else if ( input[ind] == '*')
	{
		flags->flags |= FLAG_SHR_ARG;
		flags->shirina = va_arg(arg, int);
		if (flags->shirina < 0)
		{
			flags->flags |= FLAG_FLG_MIN;
			flags->shirina*= -1;
		}
		ind++;
	}
	if ( input[ind] == '.')
	{
		ind++;
		if ( input[ind] >= '0' &&  input[ind] <= '9')
		{
			flags->flags |= FLAG_PRS_DIG;
			flags->precision = ft_atoi(input + ind);
			while( input[ind] >= '0' &&  input[ind] <= '9')
				ind++;
		}
		else if ( input[ind] == '*')
		{
			flags->flags |= FLAG_PRS_ARG;
			flags->precision = va_arg(arg, int);
			if (flags->precision < 0)
				flags->precision*= -1;
			ind++;
		}
		else if (ft_strchr("diucspfxX",  input[ind]))
		{
			flags->flags |= FLAG_PRS_DIG;
			flags->precision = 0;
		}
	}
	if ( input[ind] == 'd' ||  input[ind] == 'i')
		flags->flags |= FLAG_TYP_D;
	else if ( input[ind] == 'u')
		flags->flags |= FLAG_TYP_U;
	else if ( input[ind] == 'c')
		flags->flags |= FLAG_TYP_C;
	else if ( input[ind] == 's')
		flags->flags |= FLAG_TYP_S;
	else if ( input[ind] == 'p')
		flags->flags |= FLAG_TYP_P;
	else if ( input[ind] == 'x')
		flags->flags |= FLAG_TYP_X;
	else if ( input[ind] == 'X')
		flags->flags |= FLAG_TYP_XB;
	else if ( input[ind] == 'f')
		flags->flags |= FLAG_TYP_F;
	return (++ind);
}
