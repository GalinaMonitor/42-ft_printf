/*
**@file					ft_strlcat.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function concatenate two strings
**
**@used_functions		ft_strlen, ft_memchr, ft_strlcpy
*/
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	dest = ft_memchr(dest, '\0', size);
	if (dest == NULL)
		return (size + len_src);
	ft_strlcpy(dest, src, size - len_dest);
	return (len_src + len_dest);
}
