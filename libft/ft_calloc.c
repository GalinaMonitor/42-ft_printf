/*
**@file					ft_calloc.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function allocates nmemb cells of size and fills them with '\0'
**
**@used_functions		ft_bzero, malloc
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	if (mem)
		ft_bzero(mem, size * nmemb);
	return (mem);
}
