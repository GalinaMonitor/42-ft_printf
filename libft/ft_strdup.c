/*
**@file					ft_strdup.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function allocate memory and duplicate str
**
**@used_functions		ft_strlen, ft_calloc, ft_strlcpy
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s);
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, size + 1);
	return (str);
}
