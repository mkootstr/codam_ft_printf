#include "ft_printf.h"

int	process(char *string, va_list args, int rv)
{
	if (string[0] == 'c' || string[0] == 's')
		rv = rv + charstr(args, string[0]);
	if (string[0] == 'x')
		rv = rv + hex(args, 97);
	if (string[0] == 'X')
		rv = rv + hex(args, 65);
	if (string[0] == 'u')
		rv = rv + unsign(args);
	if (string[0] == 'd' || string[0] == 'i')
		rv = rv + integ(args);
	if (string[0] == 'p')
		rv = rv + ptr(args);
	if (string[0] == '%')
	{
		write(1, "%", 1);
		rv = rv + 1;
	}
	return (rv);
}

char *findspec(char *string)
{
	int i;

	i = 0;
	while (string[i] != '%' && string[i] != '\0')
		i++;
	if (string[i] == '%')
		return (string + i + 1);
	else 
		return (NULL);
}

int printstr(char *string)
{
	int i;

	i = 0;
	while (string[i] != '%' && string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}

int	sort(char *string, va_list args)
{
	int		rv;

    rv = 0;
	while (string)
	{
		rv = rv + printstr(string);
		string = findspec(string);
		if (!string)
			return (rv);
		rv = process(string, args, rv);
        string++;
	}
	return (rv);
}

int ft_printf(const char *string, ...)
{
    va_list	args;
	int		rv;

    va_start(args, string);
	rv = sort((char *)string, args);
    va_end(args);
	return (rv);
}