/*
**@file					ft_toupper.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Text-transform: uppercase
**
**@used_functions		{none}
*/
#include "libft.h"

int	ft_toupper(int str)
{
	if (str >= 'a' && str <= 'z')
		return (str - 32);
	return (str);
}
