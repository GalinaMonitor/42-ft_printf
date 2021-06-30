#include "ft_printf.h"

// int	ft_processor(va_list arg, flags *flags)
// {
// 	char	*str;

// 	str = ft_type_parse(arg, flags);

// 	if(flags->flags & (FLAG_PRS_ARG | FLAG_PRS_DIG))
// 		str = ft_precision(str, flags);
// 	if(flags->flags & (FLAG_SHR_ARG | FLAG_SHR_DIG))
// 		str = ft_shirina(str, flags);

// 	ft_putstr_fd(str, 1);
// 	flags->count_print += ft_strlen(str);
// 	return 0;
// }

// int	ft_check_args_string(const char *input, flags *flags)
// {
// 	int ind;
// 	ind = 0;
// 	while ((!ft_strchr("%dicsupxX", input[ind])) && input[ind])
// 		ind++;
// 	if (input[ind] == '%')
// 	{
// 		ft_putchar_fd(input[ind], 1);
// 		flags->count_print += 1;
// 		return ++ind;
// 	}
// 	if (input[ind])
// 		return 0;
// 	return -1;
// }

// int ft_parse(va_list arg, const char *input)
// {
// 	flags *flags;
// 	int check_proc;


// 	flags = malloc(sizeof(flags));
// 	flags->count_print = 0;
// 	while(*input)
// 	{
// 		if (*input == '%')
// 		{
// 			check_proc = ft_check_args_string(++input, flags);
// 			if (check_proc == 0)
// 			{
// 				input = ft_parser_GOD(input, arg, flags);
// 				ft_processor(arg, flags);
// 			}
// 			else if (check_proc == -1)
// 				return (-1);
// 			else
// 				input+= check_proc;
// 		}
// 		else
// 		{
// 			ft_putchar_fd(*(input++), 1);
// 			flags->count_print += 1;
// 		}
// 	}
// 	return (flags->count_print);
// }

// int ft_printf(const char *input, ...)
// {
// 	va_list arg;
// 	int count_print;
// 	va_start(arg, input);
// 	count_print = ft_parse(arg, input);
// 	va_end(arg);
// 	return (count_print);
// }

unsigned long long	*ft_long_digits_power(unsigned long long *digits, int power)
{
	int size = 10;
	int ind1 = 0;
	int ind2 = 0;
	int base = 1000000000;
	unsigned long long	*result;
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
			result = ft_long_digits_multiply(result, digits);
	}
	else if (power == 0)
		result[0] = 1;

	return (result);
}


int main()
{
	int count = 0;
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

	u1.digit = 3.0625;

	power = u1.exponent - 16383;
	nbr = ft_long_digits_power(ft_long_digits(2), power);
	ind = 63;

	while (--ind > 0 && power-- > 0)
	{

		if ((u1.mantissa >> ind) & 1)
			nbr = ft_long_digits_sum(nbr, ft_long_digits_power(ft_long_digits(2), power));
	}


	ft_long_digits_printf(nbr);
	printf(".");

	power = u1.exponent - 16383;
	fract = ft_long_digits(0);
	while (ind > 0)
	{
		if ((u1.mantissa >> ind) & 1)
		{
			fract = ft_long_digits_sum(fract, ft_long_digits_power(ft_long_digits(5), ind1));


			//printf("1");
		}
		//else
			//printf("0");
		fract = ft_long_digits_multiply(ft_long_digits(10), fract);
		ft_long_digits_printf(fract);
		ind--;
		ind1++;
	}
	printf("\n");
	ft_long_digits_printf(fract);
	// long long	digits[10];
	// long long	digits2[10];
	// while(ind1 < 10)
	// {
	// 	digits[ind1] = 0;
	// 	digits2[ind1] = 0;
	// 	ind1++;
	// }
	// long long *dig = ft_long_digits_division(ft_long_digits(19990, digits), 51);
	// printf("%lld", *(dig+4) );
	// printf("%lld", *(dig+3) );
	// printf("%lld", *(dig+2) );
	// printf("%lld", *(dig+1) );
	// printf("%lld", *(dig) );




	return 0;
}
