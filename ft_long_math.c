/*
**@file					ft_long_math.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief 				List of funcs, used for operations with extra-long digits
**
**@used_functions		ft_long_digits, ft_long_digits_sum, ft_long_digits_division,
**						ft_long_digits_multiply, ft_long_digits_to_str, ft_strdup,
**						ft_strjoin, ft_itoa_base, ft_itoa_base, ft_long_digits_power
*/

#include "ft_printf.h"

/*
**@brief 			Function translates digit into extra-long digit format
**
**@param			nbr
**@param			base
**@return			unsigned long long*
*/

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

/*
**@brief 			Function makes sum of two extra-long digits
**
**@param			digits
**@param			digits2
**@param			base
**@return			unsigned long long*
*/

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

/*
**@brief 			Function makes a division of extra-long digit and normal digit
**
**@param			digits
**@param			num
**@param			base
**@return			unsigned long long*
*/

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

/*
**@brief 			Function multiplicate two extra-long digits
**
**@param			digits
**@param			digits2
**@param			base
**@return			unsigned long long*
*/

unsigned long long	*ft_long_digits_multiply(unsigned long long *digits, unsigned long long *digits2, unsigned long long base)
{
	int size = 10;
	int ind1 = -1;
	int ind2 = 0;
	unsigned long long	*result;

	if (base == 10)
		size = 100;
	result = malloc(sizeof(long long) * size);
	while(ind1 < size)
		result[ind1++] = 0;
	ind1 = 0;
	while (ind1 < size && digits[ind1] > 0)
	{
		while (ind2 < size && size > (ind1 + ind2) && digits2[ind2] > 0)
		{
			result[ind1 + ind2] += digits[ind1] * digits2[ind2];
			ind2++;
		}
		ind2 = 0;
		ind1++;
	}
	ind1 = -1;
	while (++ind1 < size)
		if (result[ind1] > base)
		{
			result[ind1 + 1]+= result[ind1] / base;
			result[ind1]%= base;
		}
	return (result);
}

/*
**@brief 			Function translate extra-long digit into string
**
**@param			digits
**@param			base
**@param			count
**@param			flags
**@return			char*
*/

char	*ft_long_digits_to_str(unsigned long long **digits, unsigned long long base, int count, t_flags *flags)
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
		while (count-- > 0)
			str = ft_strjoin(str, ft_itoa_base(digits[0][count], 10, flags));
	else
	{
		while (digits[0][size - 1] == 0)
			size--;
		while (size > 0)
		{
			str = ft_strjoin(str, ft_itoa_base(digits[0][size - 1], 10, flags));
			size--;
		}
	}
	return (str);
}

/*
**@brief 			Function raise to a power extra-long digit
**
**@param			digits
**@param			power
**@param			base
**@return			unsigned long long*
*/

unsigned long long	*ft_long_digits_power(unsigned long long *digits, int power, unsigned long long base)
{
	int size;
	int ind1;
	unsigned long long	*result;

	size = 10;
	ind1 = 0;
	if (base == 10)
		size = 100;
	result = malloc(sizeof(long long) * size);
	while(ind1 < size)
		result[ind1++] = 0;
	if (power >= 1)
	{
		result[0] = 1;
		while(power-- > 0)
			result = ft_long_digits_multiply(result, digits, base);
	}
	else if (power == 0)
		result[0] = 1;
	else if (power < 0)
		result[0] = 0;
	return (result);
}
