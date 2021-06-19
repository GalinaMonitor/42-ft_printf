/*
**@file					ft_strnew.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function allocate memory for count chars + 1
**
**@used_functions		ft_memalloc
**						!No protection from input NULL!
*/
#include "libft.h"

char	*ft_strnew(size_t count)
{
	return ((char *)ft_memalloc(sizeof(char) * count + 1));
}
