/*
**@file					ft_strjoin.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function allocate memory and joins two strings
**
**@used_functions		ft_strlen, ft_calloc, ft_strlcpy
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count_s1;
	int		count_s2;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count_s1 = ft_strlen(s1);
	count_s2 = ft_strlen(s2);
	dest = ft_calloc(count_s1 + count_s2 + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, count_s1 + 1);
	dest += count_s1;
	*dest = '1';
	ft_strlcpy(dest, s2, count_s2 + 1);
	dest -= count_s1;
	return (dest);
}
