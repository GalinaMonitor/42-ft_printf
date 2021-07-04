#include "ft_printf.h"

char	*ft_precision_str(char *str, flags *flags)
{
	int		size;
	int		length;
	int		ind;
	char	*result;

	ind = 0;
	length = ft_strlen(str);
	if (flags->precision < length)
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (length + 1));
		size = length;
	}
	while(size-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	result[ind] = '\0';
	return(result);
}

char	*ft_precision_digits(char *str, flags *flags)
{
	int		size;
	int		length;
	int		ind;
	char	*result;

	ind = 0;
	length = ft_strlen(str);
	if (flags->precision > length || *str == '0')
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (length + 1));
		size = length;
	}

	if(*str == '-')
	{
		result[ind++] = *str;
		str++;
		length--;
	}
	while(flags->precision - length > 0)
	{
		result[ind++] = '0';
		length++;
		size--;
	}
	while(size-- > 0)
	{
		result[ind++] = *str;
		str++;
	}
	result[ind] = '\0';
	return(result);
}

char	*ft_precision_float(char *str, flags *flags)
{
	int	ind1;
	int	ind2;
	int ind3;
	int finish;
	int		print;
	char *result;
	int sum;

	finish = 0;
	ind1 = 0;
	ind3 = 1;
	if (flags->precision == -1)
		flags->precision = 6;
	while (str[ind1] != '.')
		ind1++;
	ind2 = flags->precision;
	if (flags->precision == 0)
		sum = ind1;
	else
		sum = ind1 + ind2 + 1;
	if (str[ind2 + ind1 + 1] >= '5')
	{
		while (ind2 > 1)
		{
			if (str[ind2 + ind1] != '9')
			{
				str[ind2 + ind1]+= 1;
				finish = 1;
				break;
			}
			else if (str[ind2 + ind1] == '9')
				str[ind2 + ind1] = '0';
			ind2--;
		}
		if (finish == 0)
		{
			ind1--;
			while (ind1 >= 0)
			{
				if (str[ind1] != '9')
				{
					str[ind1]+= 1;
					finish = 1;
					break;
				}
				else if (str[ind1] == '9')
				{
					str[ind1] = '0';
				}
				ind1--;
			}
		}
		ind1 = 0;
		ind2 = 0;
		if (finish == 0)
		{
			result = malloc(sizeof(char) * (sum + 2));
			result[ind1] = '1';
			ind1++;
			print = ft_strlcpy((result + 1), str, sum + 1);
		}
		else
		{
			result = malloc(sizeof(char) * (sum + 1));
			print = ft_strlcpy((result), str, sum + 1);
		}
	}
	else
	{
		result = malloc(sizeof(char) * (sum + 1));
		print = ft_strlcpy(result, str, sum + 1);
	}
	if (flags->precision == 0 && str[sum + 1] == '5')
	{
		while (str[sum + 1 + ind3] && str[sum + 1 + ind3] == '0')
		{
			ind3++;
		}
		if (str[sum + 1 + ind3])
		{
			while (sum > 0)
			{
				if (str[sum - 1] != '9')
				{
					str[sum - 1]+= 1;
					return (result);
				}
				else if (str[sum - 1] == '9')
					str[sum - 1] = '0';
				sum--;
			}
			result = ft_strjoin("1", result);
		}
	}
	if (print < sum)
	{
		while (print < sum)
		{
			result[print] ='0';
			print++;
		}
		result[print] = '\0';
	}
	return (result);
}
