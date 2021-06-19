/*
**@file					ft_lstsize.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief 				Function counts the number of elements in a list
**
**@used_functions		{none}
*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst != NULL)
	{
		if (lst->next)
		{
			return (ft_lstsize(lst->next) + 1);
		}
		return (1);
	}
	return (0);
}
