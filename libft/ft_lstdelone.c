/*
**@file					ft_lstdelone.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function takes as a parameter an element and frees the
**						memory of the element’s content using the function
**						’del’ given as a parameter and free the element.
**						The memory of ’next’ must not be freed.
**
**@used_functions		free
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
		del(lst->content);
	free(lst);
}
