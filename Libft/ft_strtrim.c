/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:36:50 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/01/18 13:13:14 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_getstart(char const *s1, const char *set)
{
	size_t	s1_index;
	size_t	set_index;

	s1_index = 0;
	set_index = 0;
	while (set[set_index] != '\0')
	{
		if (s1[s1_index] == set[set_index])
		{
			s1_index++;
			set_index = 0;
		}
		if (s1[s1_index] != set[set_index])
		{
			set_index++;
		}
	}
	return (s1_index);
}

static size_t	ft_getstop(const char *s1, const char *set)
{
	size_t	s1_index;
	size_t	set_index;

	s1_index = 0;
	set_index = 0;
	while (s1[s1_index] != '\0')
	{
		s1_index++;
	}
	s1_index--;
	while (set[set_index] != '\0' && set[0] != '\0')
	{
		if (s1[s1_index] == set[set_index])
		{
			s1_index--;
			set_index = 0;
		}
		if (s1[s1_index] != set[set_index])
			set_index++;
	}
	return (s1_index);
}

static char		*ft_newstring(size_t start, size_t stop, const char *s1)
{
	size_t	s2_index;
	size_t	size;
	char	*s2;

	s2_index = 0;
	size = stop - start + 2;
	if (s1[0] == '\0' || s1[start] == '\0')
		size = 1;
	s2 = malloc(size * sizeof(char));
	if (s2 != NULL)
	{
		while (start <= stop && stop != 0 && s1[start] != '\0')
		{
			s2[s2_index] = s1[start];
			start++;
			s2_index++;
		}
		s2[s2_index] = '\0';
		return (s2);
	}
	else
		return (NULL);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	stop;
	char	*s2;

	if (!s1)
		return (NULL);
	start = ft_getstart(s1, set);
	stop = ft_getstop(s1, set);
	s2 = ft_newstring(start, stop, s1);
	if (!s2)
		return (NULL);
	return (s2);
}
