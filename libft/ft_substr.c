/*
**@file					ft_substr.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Allocates (with malloc(3)) and returns a substring
						from the string ’s’.
						The substring begins at index ’start’ and is of
						maximum size ’len’.
**
**@used_functions		ft_strdup, ft_calloc
*/
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	int		temp;
	size_t	dlina;
	int		ind;

	ind = 0;
	dlina = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	temp = len;
	if (len == 0 || start >= dlina)
		return (ft_strdup(""));
	if (dlina >= len)
		dest = ft_calloc(len + 1, sizeof(char));
	else
		dest = ft_calloc(dlina + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	str += start;
	while (*str && len-- > 0)
	{
		dest[ind++] = *str;
		str++;
	}
	return (dest);
}
