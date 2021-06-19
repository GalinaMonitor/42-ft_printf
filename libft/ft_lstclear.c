/*
**@file					ft_lstclear.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Deletes and frees the given element and every successor
**						of that element, using the function ’del’ and free(3).
**						Finally, the pointer to the list must be set to NULL.
**
**@used_functions		ft_lstdelone
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst != NULL)
	{
		ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
