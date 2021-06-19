/*
**@file					ft_memchr.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function checks nmb cells and tries to find char c.
**						Function can find '\0'
**
**@used_functions		{none}
*/
#include "libft.h"

void	*ft_memchr(void *src, int c, size_t nmb)
{
	unsigned char	*src_cast;

	src_cast = (unsigned char *)src;
	while (nmb > 0)
	{
		if (*src_cast == (unsigned char)c)
			return (src_cast);
		src_cast++;
		nmb--;
	}
	return (NULL);
}
