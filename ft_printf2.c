#include "ft_printf.h"

static int	ft_isin(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_format_parcing(const char **fmt)
{
	while(*(*fmt += 1) && !ft_isin(CNV, **fmt))
	{
		ft_putchar_fd(**fmt, 1);
		// *fmt += 1;
	}
	// *fmt = *fmt;
	// ft_putchar_fd('\n', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	va_start(ap, format);
	i = 0;
	len = 0;

	int foo = ft_strlen(format);
	int y = 0;
	while (*format && y < foo)
	{
		// printf("\nwhile <%p>\n", format);
		if (*format == '%')
		{
			len += ft_format_parcing(&format);
			// printf("\nafter <%p>\n", format);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			len++;
		}
		// y++;
		// break;
	}
	ft_putchar_fd('\n', 1);
	return (i + len);
}

// gcc mega.c ft_itoa_base.c ft_printf.c libft/libft.a

// #include <stdio.h>
// #include <stdarg.h>

// void
// foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */
// {
// 	va_list ap;
// 	int d;
// 	char c;
// 	char *s;

// 	va_start(ap, fmt);
// 	while (*fmt)
// 		switch (*fmt++) {
// 		case 's':              /* string */
// 			s = va_arg(ap, char *);
// 			printf("string %s\n", s);
// 			break;
// 		case 'd':              /* int */
// 			d = va_arg(ap, int);
// 			printf("int %d\n", d);
// 			break;
// 		case 'c':              /* char */
// 			/* need a cast here since va_arg only
// 				takes fully promoted types */
// 			c = (char) va_arg(ap, int);
// 			printf("char %c\n", c);
// 			break;
// 		}
// 	va_end(ap);
// }