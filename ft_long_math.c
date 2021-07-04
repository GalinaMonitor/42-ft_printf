#include "ft_printf.h"

unsigned long long	*ft_long_digits(unsigned long long nbr, unsigned long long base)
{
	int size = 10;
	int ind1 = 0;
	unsigned long long *digits;

	if (base == 10)
		size = 100;

	digits = malloc(sizeof(unsigned long long) * size);
	while(ind1 < size)
	{
		digits[ind1] = 0;
		ind1++;
	}
	ind1 = 0;
	while (nbr > 0)
	{
		digits[ind1++] = nbr % base;
		nbr/= base;
	}

	return(digits);
}


unsigned long long	*ft_long_digits_sum(unsigned long long *digits, unsigned long long *digits2, unsigned long long base)
{
	int size = 10;
	int ind1 = 0;

	if (base == 10)
		size = 100;


	while (ind1 < size)
	{
		digits[ind1] += digits2[ind1];
		ind1++;
	}
	ind1 = 0;
	while (ind1 < size)
	{
		if (digits[ind1] > base)
		{
			digits[ind1 + 1]+= 1;
			digits[ind1]%= base;
		}
		ind1++;
	}
	free(digits2);
	return (digits);
}

unsigned long long	*ft_long_digits_division(unsigned long long *digits, unsigned long long num, unsigned long long base)
{
	int size = 10;
	int temp = size;

	if (base == 10)
		size = 100;


	while (temp-- > 0)
	{
		digits[temp - 1] += digits[temp] % num * base;
		digits[temp] = digits[temp] / num;
	}
	return (digits);
}

// unsigned long long	*ft_long_digits_min(unsigned long long *digits, long long *digits2, unsigned long long base)
// {
// 	int size = 10;
// 	int ind1 = 0;
// 	int ind2 = 0;

// 	if (base == 10)
// 		size = 100;

// 	while (ind1 < size)
// 	{
// 		digits[ind1] -= digits2[ind1];
// 		ind1++;
// 	}
// 	ind1 = 0;

// 	while (ind1 < size)
// 	{
// 		if (digits[ind1] < 0)
// 		{
// 			digits[ind1 + 1]-= 1;
// 			digits[ind1]+= base;
// 		}
// 		ind1++;
// 	}

// 	return (digits);
// }


unsigned long long	*ft_long_digits_multiply(unsigned long long *digits, unsigned long long *digits2, unsigned long long base)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	unsigned long long	*result;

	if (base == 10)
		size = 100;

	result = malloc(sizeof(long long) * size);
	while(ind1 < size)
	{
		result[ind1] = 0;
		ind1++;
	}
	ind1 = 0;
	while (ind1 < size) //&& digits[ind1] >= 0 && digits2[ind2] >= 0
	{
		while (ind2 < size && size > (ind1 + ind2))
		{
			result[ind1 + ind2] += digits[ind1] * digits2[ind2];
			ind2++;
		}
		ind2 = 0;
		ind1++;
	}
	ind1 = 0;
	while (ind1 < size)
	{
		if (result[ind1] > base)
		{
			result[ind1 + 1]+= result[ind1] / base;
			result[ind1]%= base;
		}
		ind1++;
	}
	free(digits);
	free(digits2);
	return (result);
}

char	*ft_long_digits_to_str(unsigned long long *digits, unsigned long long base, int count, flags *flags)
{
	int size = 10;
	char *str;

	str = ft_strdup("");

	if (base == 10)
		size = 100;
	if (flags->flags & FLAG_TYP_FMIN)
		{
			str = ft_strdup("-");
			flags->flags ^= FLAG_TYP_FMIN;
		}
	if (count > 0)
	{
		while (count-- > 0)
		{
			str = ft_strjoin(str, ft_itoa_base(digits[count], 10, flags));
		}
	}
	else
	{
		while (digits[size - 1] == 0)
			size--;
		while (size > 0)
		{
			str = ft_strjoin(str, ft_itoa_base(digits[size - 1], 10, flags));
			size--;
		}
	}
	free(digits);
	return (str);
}

unsigned long long	*ft_long_digits_power(unsigned long long *digits, int power, unsigned long long base)
{
	int size = 10;
	int ind1 = 0;
	unsigned long long	*result;

	if (base == 10)
		size = 100;


	result = malloc(sizeof(long long) * size);
	while(ind1 < size)
	{
		result[ind1] = 0;
		ind1++;
	}
	if (power >= 1)
	{
		result[0] = 1;
		while(power-- > 0)
			result = ft_long_digits_multiply(result, digits, base);
	}
	else if (power == 0)
		result[0] = 1;
	free(digits);
	return (result);
}
