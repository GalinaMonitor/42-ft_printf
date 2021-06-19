/*
**@file					ft_memmove.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function copies nmb cells from src to dest. Pointers may overlap
**
**@used_functions		{none}
*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t nmb)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	if (src > dest)
		while (nmb-- > 0)
			*dest_cast++ = *src_cast++;
	else if (src < dest)
	{
		src_cast += nmb - 1;
		dest_cast += nmb - 1;
		while (nmb-- > 0)
		{
			*dest_cast = *src_cast;
			dest_cast--;
			src_cast--;
		}
	}
	return (dest);
}
