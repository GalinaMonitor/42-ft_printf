/*
**@file					ft_itoa.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function makes char from int
**
**@used_functions		ft_intlen, ft_strnew
*/

#include "libft.h"

/*
**@brief			Function counts digits
**
**@param			n
**@return			int
*/
static int	ft_intlen(long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_unsigned(char *word, int ind, long n)
{
	while (n > 0)
	{
		word[ind] = n % 10 + 48;
		n /= 10;
		ind--;
	}
	return (word);
}

char	*ft_itoa(long long int nbr)
{
	long	n;
	int		ind;
	int		count;
	char	*word;

	n = (long)nbr;
	ind = 0;
	count = ft_intlen(n);
	word = ft_calloc(count + 2, sizeof(char));
	if (word == NULL)
		return (NULL);
	ind += count - 1;
	if (n < 0)
	{
		word[0] = '-';
		n *= -1;
		ind++;
	}
	if (count == 0)
	{
		word[0] = '0';
		return (word);
	}
	return (ft_itoa_unsigned(word, ind, n));
}
