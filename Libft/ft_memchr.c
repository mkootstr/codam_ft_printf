/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:22:14 by marlou        #+#    #+#                 */
/*   Updated: 2021/01/18 10:51:29 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)str;
	while (n != 0)
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		n--;
		i++;
	}
	return (NULL);
}
