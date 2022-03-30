/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:59:47 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/01/13 14:22:28 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*flpfrt;

	i = 0;
	flpfrt = (unsigned char *)dest;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			flpfrt[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else if (src > dest)
	{
		while (i < n)
		{
			flpfrt[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
