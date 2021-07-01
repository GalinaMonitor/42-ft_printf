#include "ft_printf.h"

char	*ft_parsing_float()
{
	int count = 0;
	int count2 = 0;
	int power = 0;
	uint64_t *nbr;
	uint64_t *fract;
	uint64_t mant;
	uint64_t mant2;
	int ind = 1;
	int ind1 = 1;


	union U_example
	{
		long double digit;
		struct
		{
			uint64_t mantissa: 64;
			uint16_t exponent: 15;
			uint8_t minus: 1;
		};
	}u1;

	u1.digit = 4.00000047684;

	power = u1.exponent - 16383;
	nbr = ft_long_digits_power(ft_long_digits(2, 1000000000), power, 1000000000);
	ind = 63;

	while (--ind > 0 && power-- > 0)
	{

		if ((u1.mantissa >> ind) & 1)
			nbr = ft_long_digits_sum(nbr, ft_long_digits_power(ft_long_digits(2, 1000000000), power, 1000000000), 1000000000);
	}


	ft_long_digits_printf(nbr, 1000000000, 0);
	printf(".");

	power = u1.exponent - 16383;
	fract = ft_long_digits(0, 10);
	while (ind > 0)
	{
		if ((u1.mantissa >> ind) & 1)
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
	ft_long_digits_printf(fract, 10, count2);
	printf("\nTEST = %-23.4f", 0.5);

	return 0;
}
