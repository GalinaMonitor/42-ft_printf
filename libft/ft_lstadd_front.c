/*
**@file					ft_lstadd_front.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function adds the element ’new’ at the beginning of the list
**
**@used_functions		{none}
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != NULL && new != NULL)
		new->next = *lst;
	*lst = new;
}
