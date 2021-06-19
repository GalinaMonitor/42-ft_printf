/*
**@file					ft_split.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Allocates (with malloc(3)) and returns an array
**						of strings obtained by splitting ’s’ using the
**						character ’c’ as a delimiter. The array must be
**						ended by a NULL pointer.
**
**@used_functions		ft_char_count, ft_words_count, ft_clean, ft_calloc, ft_strlcpy
*/

#include "libft.h"

/*
**@brief			Function counts chars in a word
**
**@param			s
**@param			c
**@return			int
*/
static int	ft_char_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s)
	{
		s++;
		count++;
	}
	return (count);
}

/*
**@brief			Function counts words in a string
**
**@param			s
**@param			c
**@return			int
*/
static int	ft_words_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

/*
**@brief			Function frees the **mass
**
**@param			mass
*/
static void	ft_clean(char **mass)
{
	int	ind;

	ind = 0;
	while (mass[ind])
	{
		free(mass[ind]);
		ind++;
	}
	free(mass);
}

static char const	*ft_words_creator(char **mass,
		char const *s, char c, int ind)
{
	int		word_size;

	while (*s == c)
		s++;
	word_size = ft_char_count(s, c);
	mass[ind] = ft_calloc(word_size + 1, sizeof(char));
	if (mass[ind] == NULL)
		return (NULL);
	ft_strlcpy(mass[ind++], s, word_size + 1);
	s += word_size;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		ind;
	char	**mass;

	if (s == NULL)
		return (NULL);
	ind = 0;
	words = ft_words_count(s, c);
	mass = (char **)malloc(sizeof(char *) * (words + 1));
	if (mass == NULL)
		return (NULL);
	while (words-- > 0)
	{
		s = ft_words_creator(mass, s, c, ind);
		if (s == NULL)
		{
			ft_clean(mass);
			return (NULL);
		}
		ind++;
	}
	mass[ind] = NULL;
	return (mass);
}
