#include "ft_printf.h"

static int	ft_intlen_base16(long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_itoa_unsigned_base16(char *word, int ind, long n, flags *flags)
{
	int temp;

	while (n > 0)
	{
		temp = n % 16 + 48;
		if (temp > 57 && flags->flags & FLAG_TYP_XB)
			temp+= 7;
		else if (temp > 57 && (flags->flags & FLAG_TYP_X || flags->flags & FLAG_TYP_P))
			temp+= 39;
		word[ind] = temp;
		n /= 16;
		ind--;
	}
	return (word);
}

char	*ft_itoa_base16(unsigned long nbr, flags *flags)
{
	long	n;
	int		ind;
	int		count;
	char	*word;

	n = (unsigned long)nbr;
	ind = 0;
	count = ft_intlen_base16(n);
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
	return (ft_itoa_unsigned_base16(word, ind, n, flags));
}
