/*
**@file					ft_memalloc.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function allocates nmb cells and fills with '\0'
**
**@used_functions		malloc, ft_bzero
**						!No protection from input NULL!
*/
#include "libft.h"

void	*ft_memalloc(size_t nmb)
{
	void	*mem;

	mem = malloc(nmb);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmb);
	return (mem);
}
