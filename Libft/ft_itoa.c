/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 11:56:43 by mkootstr      #+#    #+#                 */
/*   Updated: 2020/12/14 12:24:18 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_swap(char *string)
{
	size_t	i;
	size_t	j;
	char	temp;

	i = 0;
	j = 0;
	temp = '\0';
	while (string[j + 1] != '\0')
	{
		j++;
	}
	while (i < j)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		j--;
		i++;
	}
	return (string);
}

static char	*ft_string(int num, int posneg, char *a)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		a[i] = '0';
		i++;
	}
	while (num != 0)
	{
		a[i] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	if (posneg == 1)
	{
		a[i] = '-';
		i++;
	}
	a[i] = '\0';
	a = ft_swap(a);
	return (a);
}

static int	ft_isneg(int num)
{
	if (num < 0)
	{
		return (1);
	}
	else
		return (0);
}

static int	ft_intlen(int num)
{
	int c;

	c = 1;
	while ((num >= 10 && num >= 0) || num <= -10)
	{
		num = num / 10;
		c++;
	}
	if (num < 0)
		c++;
	return (c);
}

char		*ft_itoa(int num)
{
	int		posneg;
	int		len;
	char	*a;

	posneg = 0;
	len = ft_intlen(num);
	a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	posneg = ft_isneg(num);
	if (posneg == 1 && num != -2147483648)
		num = -num;
	a = ft_string(num, posneg, a);
	if (num == -2147483648)
		ft_memcpy(a, "-2147483648", 12);
	return (a);
}
