/*
**@file					ft_strlcpy.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function copies up to size characters from the
**						NUL-terminated string src to dst,
**						NUL-terminating the result.
**
**@used_functions		ft_strlen
*/
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	if (src == NULL)
		return (0);
	count = ft_strlen(src);
	if (size == 0)
		return (count);
	while (*src && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
	return (count);
}
