/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 17:51:18 by marlou        #+#    #+#                 */
/*   Updated: 2021/01/25 13:12:06 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	a;
	size_t	i;

	a = nitems * size;
	i = 0;
	ptr = malloc(a);
	if (ptr != NULL)
	{
		while (i < a)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
