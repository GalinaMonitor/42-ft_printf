/*
**@file					ft_isspace.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function check if c is non-printable
**
**@used_functions		{none}
**						!No protection from input NULL!
*/

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}
