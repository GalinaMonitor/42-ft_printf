/*
**@file					ft_strrchr.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function searches the last c char in the string
**
**@used_functions		ft_strlen
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return (str + len);
	str += len - 1;
	while (len > 0)
	{
		if (*str == (char)c)
			return (str);
		str--;
		len--;
	}
	return (NULL);
}
