/*
**@file					ft_strtrim.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Allocates (with malloc(3)) and returns a copy of
**						’s1’ with the characters specified in ’set’ removed
**						from the beginning and the end of the string.
**
**@used_functions		ft_strchr, ft_strlen, ft_substr
*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	result = ft_substr((char *)s1, 0, len + 1);
	return (result);
}
