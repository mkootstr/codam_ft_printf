#include "ft_printf.h"

void ft_putnbr_base(unsigned long num, unsigned long base, int cap)
{   
	if (num >= base)
	{
		ft_putnbr_base((num / base), base, cap);
        if (num % base < 10 && num >= 0)
		    ft_putchar_fd((num % base + 48), 1);
        else if (num % base > 9)
            ft_putchar_fd((num % base % 10 + cap), 1);
    }
    else if (num < base)
    {
	    if (num < 10 && num >= 0)
		    ft_putchar_fd((num + 48), 1);
        else if (num > 9)
            ft_putchar_fd((num % 10 + cap), 1);
    }
}

int	ft_intlen(unsigned long num, unsigned long base)
{
	int c;
    
	c = 1;
    while (num >= base)
	{
		num = num / base;
		c++;
	}
	return (c);
}

int ft_intputstr_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
    return ((int) i);
}