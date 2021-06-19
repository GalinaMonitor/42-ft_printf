/*
**@file					ft_lstmap.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function iterates the list ’lst’ and applies the function
**						’f’ to the content of each element. Creates a new
**						list resulting of the successive applications of
**						the function ’f’. The ’del’ function is used to
**						delete the content of an element if needed
**
**@used_functions		ft_lstnew, ft_lstclear, ft_lstadd_back
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst != NULL)
	{
		elem = ft_lstnew(f(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
