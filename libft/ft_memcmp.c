/*
**@file					ft_memcmp.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function compare nmb cells of two pointers.
**						Returns diff between two values
**
**@used_functions		{none}
*/
#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t nmb)
{
	unsigned char	*src1_cast;
	unsigned char	*src2_cast;

	src1_cast = (unsigned char *)src1;
	src2_cast = (unsigned char *)src2;
	while (nmb > 0)
	{
		if (*src1_cast != *src2_cast)
			return (*src1_cast - *src2_cast);
		nmb--;
		src1_cast++;
		src2_cast++;
	}
	return (0);
}
