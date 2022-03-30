/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:54:12 by mkootstr      #+#    #+#                 */
/*   Updated: 2021/01/25 13:14:34 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = str;
	i = 0;
	while (n != 0)
	{
		s1[i] = 0;
		i++;
		n--;
	}
	return (str);
}
