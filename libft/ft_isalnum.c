/*
**@file					ft_isalnum.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function check if c is letter or number
**
**@used_functions		{none}
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
