#include "ft_printf.h"

unsigned long long	*ft_long_digits(unsigned long long nbr)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	long long base = 1000000000;
	unsigned long long *digits;
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


unsigned long long	*ft_long_digits_sum(unsigned long long *digits, unsigned long long *digits2)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	long long base = 1000000000;

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
	return (digits);
}

unsigned long long	*ft_long_digits_division(unsigned long long *digits, unsigned long long num)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	long long base = 1000000000;
	int temp = size;

	while (temp-- > 0)
	{
		digits[temp - 1] += digits[temp] % num * base;
		digits[temp] = digits[temp] / num;
	}
	return (digits);
}

unsigned long long	*ft_long_digits_min(unsigned long long *digits, long long *digits2)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	long long base = 1000000000;

	while (ind1 < size)
	{
		digits[ind1] -= digits2[ind1];
		ind1++;
	}
	ind1 = 0;

	while (ind1 < size)
	{
		if (digits[ind1] < 0)
		{
			digits[ind1 + 1]-= 1;
			digits[ind1]+= base;
		}
		ind1++;
	}

	return (digits);
}


unsigned long long	*ft_long_digits_multiply(unsigned long long *digits, unsigned long long *digits2)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	long long base = 1000000000;
	unsigned long long	*result;
	result = malloc(sizeof(long long) * size);
	while(ind1 < size)
	{
		result[ind1] = 0;
		ind1++;
	}
	ind1 = 0;
	while (ind1 < size && digits[ind1] > 0 && digits2[ind2] > 0)
	{
		while (ind2 < size)
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
	return (result);
}

void	ft_long_digits_printf(unsigned long long *digits)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	long long base = 1000000000;
	while(size-- > 0)
	{
		if (digits[size] != 0)
			printf("%llu", digits[size]);
	}
	printf("\n");
}

