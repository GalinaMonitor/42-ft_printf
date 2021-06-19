/*
**@file					ft_memccpy.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function copies nmb cells from src to dest. If function meets c,
**						returns pointer on the next char. Pointers mustn't overlap
**
**@used_functions		{none}
*/
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t nmb)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	while (nmb > 0 && src != dest)
	{
		*dest_cast = *src_cast;
		if (*dest_cast == (unsigned char)c)
			return (++dest_cast);
		dest_cast++;
		src_cast++;
		nmb--;
	}
	return (NULL);
}
