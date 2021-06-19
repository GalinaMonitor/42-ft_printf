/*
**@file					ft_memset.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function fills nmb cells with c
**
**@used_functions		{none}
*/
#include "libft.h"

void	*ft_memset(void *s1, int c, size_t nmb)
{
	unsigned char	*cast;

	cast = (unsigned char *)s1;
	while (nmb > 0)
	{
		*cast = (unsigned char)c;
		cast++;
		nmb--;
	}
	return (s1);
}
