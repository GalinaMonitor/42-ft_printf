/*
**@file					ft_precision_float.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-07-11
**
**@brief 				Function reallocate result-string and applies
**						precision settings on float string
**
**@used_functions		ft_fill_struct_float, ft_rounding_up,
**						ft_rounding_up_zero_prec, ft_strjoin,
**						ft_rounding_up_five_plus, ft_strlcpy,
**						ft_precision_float,
*/

#include "ft_printf.h"

/*
**@brief 			Function nulls float structure, according to args
**
**@param			input
**@param			float_length
**@param			flags
*/

void	ft_fill_struct_float(char *input, s_float_length *float_length, t_flags *flags)
{
	float_length->int_part = 0;
	if (flags->precision == -1)
		flags->precision = 6;
	while (input[float_length->int_part] != '.')
		float_length->int_part++;
	float_length->result_fract_part = flags->precision;
	if (flags->precision == 0)
		float_length->result_length = float_length->int_part;
	else
		float_length->result_length = float_length->int_part + float_length->result_fract_part + 1;
}

/*
**@brief 			Basic function for rounding up
**
**@param			count
**@param			ind
**@param			input
**@return			int
*/

int	ft_rounding_up(int count, int ind, char *input)
{
	while (count > 1)
	{
		if (input[ind + count] != '9')
		{
			input[ind + count]+= 1;
			return (1);
		}
		else if (input[ind + count] == '9')
			input[ind + count] = '0';
		count--;
	}
	return(0);
}

/*
**@brief 			Function rounds up float string with zero-precision
**
**@param			float_length
**@param			input
**@param			result
*/

void ft_rounding_up_zero_prec(s_float_length *float_length, char *input, char **result)
{
	int ind3;
	int finish;

	ind3 = 1;
	while (input[float_length->result_length + 1 + ind3] && input[float_length->result_length + 1 + ind3] == '0')
	{
		ind3++;
	}
	if (input[float_length->result_length + 1 + ind3])
	{
		finish = ft_rounding_up(float_length->result_length, float_length->result_length - 1, input);
		if (finish == 0)
			result[0] = ft_strjoin("1", result[0]);
	}
}

/*
**@brief 			Function rounds up float string with 5+ digit in the end
**
**@param			float_length
**@param			input
**@param			result
**@return			int
*/

int	ft_rounding_up_five_plus(s_float_length *float_length, char *input, char **result)
{
	int finish;

	finish = ft_rounding_up(float_length->result_fract_part, float_length->int_part, input);
	if (finish == 0)
	{
		float_length->int_part--;
		finish = ft_rounding_up(float_length->int_part, float_length->int_part, input);
	}
	if (finish == 0)
	{
		result[0] = malloc(sizeof(char) * (float_length->result_length + 2));
		result[0][0] = '1';
		return (ft_strlcpy((result[0] + 1), input, float_length->result_length + 1));
	}
	else
	{
		result[0] = malloc(sizeof(char) * (float_length->result_length + 1));
		return (ft_strlcpy(result[0], input, float_length->result_length + 1));
	}
}

/*
**@brief			Function reallocate result-string and applies
**					precision settings on float string
**
**@param			input
**@param			flags
**@return			char*
*/

char	*ft_precision_float(char *input, t_flags *flags)
{
	int				print;
	char			*result;
	s_float_length	float_length;

	print = 0;
	ft_fill_struct_float(input, &float_length, flags);
	if (flags->precision == 0 && input[float_length.result_length + 1] == '5')
		ft_rounding_up_zero_prec(&float_length, input, &result);
	else if (input[float_length.result_fract_part + float_length.int_part + 1] >= '5')
		print = ft_rounding_up_five_plus(&float_length, input, &result);
	else
	{
		result = malloc(sizeof(char) * (float_length.result_length + 1));
		print = ft_strlcpy(result, input, float_length.result_length + 1);
	}
	if (print < float_length.result_length)
	{
		while (print < float_length.result_length)
			result[print++] ='0';
		result[print] = '\0';
	}
	return (result);
}
