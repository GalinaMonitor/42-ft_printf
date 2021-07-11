#include "ft_printf.h"

int	ft_intlen_base(unsigned long long n, short base)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(unsigned long long nbr, short base, t_flags *flags)
{
	int		ind;
	char	*word;
	int		temp;

	ind = ft_intlen_base(nbr, base) - 1;
	word = ft_calloc(ind + 3, sizeof(char));
	if (word == NULL)
		return (NULL);
	if (ind == -1)
	{
		word[0] = '0';
		return (word);
	}
	while (nbr > 0)
	{
		temp = nbr % base + 48;
		if (temp > 57 && flags->flags & FLAG_TYP_XB)
			temp += 7;
		else if (temp > 57 && (flags->flags & FLAG_TYP_X \
			|| flags->flags & FLAG_TYP_P))
			temp += 39;
		word[ind--] = temp;
		nbr /= base;
	}
	return (word);
}
