/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 13:25:39 by marlou        #+#    #+#                 */
/*   Updated: 2022/05/10 16:41:05 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	charstr(va_list args, char spec)
{
	int		rv;
	char	c;
	char	*s;

	rv = 0;
	c = 0;
	s = NULL;
	if (spec == 'c')
	{
		rv = 1;
		c = va_arg(args, int);
		write(1, &c, 1);
	}
	else if (spec == 's')
	{
		s = va_arg(args, char *);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		rv = ft_intputstr_fd(s, 1);
	}
	return (rv);
}

int	integ(va_list args)
{
	int	rv;
	int	num;

	rv = 0;
	num = va_arg(args, int);
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		rv = 1;
	}
	ft_putnbr_base(num, 10, 0);
	rv = rv + ft_intlen(num, 10);
	return (rv);
}

int	hex(va_list args, int cap)
{
	int				rv;
	unsigned long	num;

	num = va_arg(args, unsigned int);
	rv = ft_intlen(num, 16);
	ft_putnbr_base(num, 16, cap);
	return (rv);
}

int	ptr(va_list args)
{
	int				rv;
	unsigned long	num;

	rv = 2;
	num = va_arg(args, unsigned long);
	rv = rv + ft_intlen(num, 16);
	write(1, "0x", 2);
	ft_putnbr_base(num, 16, 97);
	return (rv);
}

int	unsign(va_list args)
{
	int				rv;
	unsigned long	num;

	num = va_arg(args, unsigned int);
	rv = ft_intlen(num, 10);
	ft_putnbr_base(num, 10, 0);
	return (rv);
}
