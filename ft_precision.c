/*
**@file					ft_precision.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief 				Function reallocate result-string and
**						applies precision settings on string
**
**@used_functions		ft_precision_str, ft_strlen, ft_precision_digits,
**						ft_cmp_memory_length, ft_precision, ft_strjoin
*/

#include "ft_printf.h"

/*
**@brief 			Function reallocate result-string and
**					applies precision settings on string-string
**
**@param			input
**@param			flags
**@return			char*
*/

char	*ft_precision_str(char *input, t_flags *flags)
{
	int		size_of_result;
	int		len_input;
	int		ind;
	char	*result;

	ind = 0;
	len_input = ft_strlen(input);
	if (flags->precision < len_input)
	{
		result = malloc(sizeof(char) * (flags->precision + 1));
		size_of_result = flags->precision;
	}
	else
	{
		result = malloc(sizeof(char) * (len_input + 1));
		size_of_result = len_input;
	}
	while (size_of_result-- > 0)
	{
		result[ind++] = *input;
		input++;
	}
	result[ind] = '\0';
	return (result);
}

/*
**@brief 			Function reallocate result-string and
**					applies precision settings on digit-string
**
**@param			input
**@param			flags
**@return			char*
*/

char	*ft_precision_digits(char *input, t_flags *flags)
{
	int		size_of_result;
	int		len_input;
	int		ind;
	char	*result;

	ind = 0;
	len_input = ft_strlen(input);
	size_of_result = ft_cmp_memory_length(input, &result, len_input, flags);
	if (*input == '-')
	{
		result[ind++] = *(input++);
		len_input--;
	}
	while (flags->precision - len_input > 0)
	{
		result[ind++] = '0';
		len_input++;
		size_of_result--;
	}
	while (size_of_result-- > 0)
		result[ind++] = *(input++);
	result[ind] = '\0';
	return (result);
}

/*
**@brief 			Function reallocate result-string and
**					applies precision settings on string
**
**@param			input
**@param			flags
**@return			char*
*/

char	*ft_precision(char *input, t_flags *flags)
{
	char	*result;

	if (flags->flags & FLAG_TYP_S)
		result = ft_precision_str(input, flags);
	else if (flags->flags & (FLAG_TYP_D | \
		FLAG_TYP_X | FLAG_TYP_XB | FLAG_TYP_U))
	{
		result = ft_precision_digits(input, flags);
		if (flags->flags & FLAG_FLG_SHARP)
		{
			if (flags->flags & FLAG_TYP_X)
				result = ft_strjoin("0x", result);
			if (flags->flags & FLAG_TYP_XB)
				result = ft_strjoin("0X", result);
		}
		if (flags->flags & FLAG_FLG_SPC && result[0] != '-')
			result = ft_strjoin(" ", result);
		if (flags->flags & FLAG_FLG_PLUS && result[0] != '-')
			result = ft_strjoin("+", result);
	}
	else if (flags->flags & (FLAG_TYP_F))
		result = ft_precision_float(input, flags);
	else
		return (input);
	free(input);
	return (result);
}
