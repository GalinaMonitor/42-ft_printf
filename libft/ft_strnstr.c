/*
**@file					ft_strnstr.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function locates the first occurrence of the
**						null-terminated string little in the string big,
**						where not more than len characters are searched.
**						Characters that appear after a `\0' character
**						are not searched.
**
**@used_functions		ft_strlen, ft_strncmp
*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	char	*little_temp;
	char	*big_temp;

	little_temp = (char *)little;
	big_temp = (char *)big;
	n = ft_strlen(little_temp);
	if (n == 0)
		return (big_temp);
	while (*big_temp && len > n - 1)
	{
		if (ft_strncmp(big_temp, little_temp, n) == 0)
			return (big_temp);
		big_temp++;
		len--;
	}
	return (NULL);
}
