/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 15:14:46 by marlou        #+#    #+#                 */
/*   Updated: 2021/01/07 13:33:50 by marlou        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	if (num == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putchar_fd(((num % 10) + 48), fd);
	}
	if (num < 10 && num >= 0)
	{
		ft_putchar_fd((num + 48), fd);
	}
}
