#include "ft_printf.h"

char	*ft_parsing_float(long double digit, s_flags *flags)
{
	int count = 0;
	int count2 = 0;
	int power = 0;
	long long unsigned *nbr;
	long long unsigned *fract;
	int ind = 1;
	int ind1 = 1;
	char *str;
	fdigit	fdigit;

	fdigit.digit = digit;

	power = fdigit.exponent - 16383;
	nbr = ft_long_digits_power(ft_long_digits(2, 1000000000), power, 1000000000);
	ind = 63;
	if (fdigit.minus & 1)
		flags->flags |= FLAG_TYP_FMIN;
	while (--ind > 0 && power-- > 0)
	{

		if ((fdigit.mantissa >> ind) & 1)
			nbr = ft_long_digits_sum(nbr, ft_long_digits_power(ft_long_digits(2, 1000000000), power, 1000000000), 1000000000);
	}

	power = fdigit.exponent - 16383;
	fract = ft_long_digits(0, 10);
	while (ind > 0)
	{
		if ((fdigit.mantissa >> ind) & 1)
		{
			if (count > 0)
			{
				fract = ft_long_digits_multiply(ft_long_digits_power(ft_long_digits(10, 10), count, 10), fract, 10);
				count = 0;
			}
			fract = ft_long_digits_sum(fract, ft_long_digits_power(ft_long_digits(5, 10), ind1, 10), 10);

			count2 = ind1;
		}

		count++;
		ind--;
		ind1++;
	}
	str = ft_strjoin(ft_long_digits_to_str(nbr, 1000000000, 0, flags), ".");
	str = ft_strjoin(str, ft_long_digits_to_str(fract, 10, count2, flags));
	return str;
}
