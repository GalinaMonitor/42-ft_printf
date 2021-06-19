/*
**@file					ft_putnbr_fd.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function prints nb dependent on fd
**
**@used_functions		ft_putchar_fd
*/

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;

	nbr = (long)nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}
