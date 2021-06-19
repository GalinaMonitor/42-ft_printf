/*
**@file					ft_tolower.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Text-transform: lowercase
**
**@used_functions		{none}
*/
#include "libft.h"

int	ft_tolower(int str)
{
	if (str >= 'A' && str <= 'Z')
		return (str + 32);
	return (str);
}
