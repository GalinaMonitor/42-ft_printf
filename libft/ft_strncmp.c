/*
**@file					ft_strncmp.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-05-10
**
**@brief				Function compares up to num characters of the C string str1
**						to those of the C string str2. This function starts comparing
**						the first character of each string. If they are equal to each other,
**						it continues with the following pairs until the characters differ,
**						until a terminating null-character is reached,
**						or until num characters match in both strings,
**						whichever happens first.
**
**@used_functions		{none}
*/
#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t nmb)
{
	if (nmb == 0)
		return (0);
	while (nmb > 1 && *first && *second && *first == *second)
	{
		first++;
		second++;
		nmb--;
	}
	return (*(unsigned char *)first - *(unsigned char *)second);
}
