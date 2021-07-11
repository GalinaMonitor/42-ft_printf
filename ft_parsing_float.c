#include "ft_printf.h"

char	*ft_float_check_nan(s_fdigit *fdigit, t_flags *flags, char *str)
{
	str = NULL;
	if (fdigit->exponent == 32767)
	{
		if (fdigit->minus == 1 && fdigit->mantissa == 9223372036854775808u)
			str = ft_strdup("-inf");
		else if (fdigit->minus == 0 && fdigit->mantissa == 9223372036854775808u)
			str = ft_strdup("inf");
		else if (fdigit->mantissa != 0)
			str = ft_strdup("nan");
		flags->flags = 0;
	}

	return (str);
}

int	ft_parsing_float_int(int power, long long unsigned **nbr, t_flags *flags, s_fdigit *fdigit)
{
	int ind;

	nbr[0] = ft_long_digits_power(ft_long_digits(2, 1000000000), power, 1000000000);
	ind = 63;
	if (fdigit->minus & 1)
		flags->flags |= FLAG_TYP_FMIN;
	while (--ind > 0 && power-- > 0)
	{
		if ((fdigit->mantissa >> ind) & 1)
			nbr[0] = ft_long_digits_sum(nbr[0], ft_long_digits_power(ft_long_digits(2, 1000000000), power, 1000000000), 1000000000);
	}
	return (ind);
}

int	ft_parsing_float_fract(int ind, long long unsigned **fract, s_fdigit *fdigit)
{
	int count;
	int count2;
	int ind1;

	count = 0;
	count2 = 0;
	ind1 = 0;
	ind++;
	while (ind > 0)
	{
		if ((fdigit->mantissa >> ind) & 1)
		{
			if (count > 0)
			{
				fract[0]= ft_long_digits_multiply(ft_long_digits_power(ft_long_digits(10, 10), count, 10), fract[0], 10);
				count = 0;
			}
			fract[0] = ft_long_digits_sum(fract[0], ft_long_digits_power(ft_long_digits(5, 10), ind1, 10), 10);
			count2 = ind1;
		}
		count++;
		ind1++;
		ind--;
	}
	return (count2);
}

char	*ft_parsing_float(va_list arg, t_flags *flags)
{
	long long unsigned *nbr;
	long long unsigned *fract;
	int ind;
	// int count2;
	char *str;
	s_fdigit	fdigit;

	long double digit = va_arg(arg, long double);
	fdigit.digit = digit;
	str = NULL;
	str = ft_float_check_nan(&fdigit, flags, str);
	if (str == NULL)
	{
		ind = ft_parsing_float_int(fdigit.exponent - 16383, &nbr, flags, &fdigit);
		fract = ft_long_digits(0, 10);
		// count2 = ft_parsing_float_fract(ind, &fract, flags, fdigit);
		// str = ft_strjoin(ft_long_digits_to_str(nbr, 1000000000, 0, flags), ".");
		// str = ft_strjoin(str, ft_long_digits_to_str(fract, 10, count2, flags));
		str = ft_strjoin(ft_long_digits_to_str(&nbr, 1000000000, 0, flags), ".");
		str = ft_strjoin(str, ft_long_digits_to_str(&fract, 10, ft_parsing_float_fract(ind, &fract, &fdigit), flags));
	}
	return str;
}
