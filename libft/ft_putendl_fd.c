/*
**@file					ft_putendl_fd.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function prints c and '\n' dependent on fd
**
**@used_functions		ft_putstr_fd, ft_putchar_fd
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
