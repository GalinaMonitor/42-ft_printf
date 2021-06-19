/*
**@file					ft_lstiter.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function iterates the list ’lst’ and applies the function
**						’f’ to the content of each element.
**
**@used_functions		{none}
*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL)
	{
		(*f)(lst->content);
		if (lst->next)
			return (ft_lstiter(lst->next, f));
	}
}
