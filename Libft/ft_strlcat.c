/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 12:18:17 by marlou        #+#    #+#                 */
/*   Updated: 2021/01/13 14:23:27 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t i;
	size_t a;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	a = size - dstlen;
	if (size == 0)
		return (srclen);
	else if (dstlen >= size)
		return (size + srclen);
	while (a > 1 && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
		a--;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
