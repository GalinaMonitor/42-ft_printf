/*
**@file					ft_lstlast.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function returns the last element of the list
**
**@used_functions		{none}
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
		if (lst->next)
			return (ft_lstlast(lst->next));
	return (lst);
}
