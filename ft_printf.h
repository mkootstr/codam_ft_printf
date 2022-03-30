#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int ft_intputstr_fd(char *s, int fd);
int charstr(va_list args, char spec);
int printstr(char *string);
int	sort(char *string, va_list args);
char *findspec(char *string);
int ft_printf(const char *string, ...);
int	ft_intlen(unsigned long num, unsigned long base);
int unsign(va_list args);
int	process(char *string, va_list args, int rv);
void ft_putnbr_base(unsigned long num, unsigned long base, int cap);
int integ(va_list args);
int hex(va_list args, int cap);
int	ptr(va_list args);

#endif