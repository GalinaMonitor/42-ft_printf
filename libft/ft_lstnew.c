/*
**@file					ft_lstnew.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function allocates (with malloc(3)) and returns a new
**						element. The variable ’content’ is initialized
**						with the value of the parameter ’content’. The
**						variable ’next’ is initialized to NULL.
**
**@used_functions		malloc
*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
