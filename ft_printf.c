/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:21:39 by znichola          #+#    #+#             */
/*   Updated: 2022/10/13 15:39:45 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// takes the format string and returns a chunk of string that needs to be printed.
//	it modifes the format string pointer to point to the next character

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	c;
	size_t	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			// %[flags][width][.precision][length]specifier 
			printf("\n	inside bizz fmt <%c>\n", *format);
			c = ft_formatted_chunk(&format, ap);
			printf("\n	left bizz fmt <%c> <%zu>\n", *format, c);
		}
		else
		{
			printf("\n	inside bang! <%c>\n", *format);
			c = ft_raw_chunk(&format);
			printf("\n	left bang! <%c> <%zu>\n", *format, c);
		}	
		count += c;
	}
	return (count);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	int test = 123;

	printf("test us : <%- .2d>", test);
	printf("\n binary test: %-s", ft_itoa_base(16384, "0123456789ABCDEFG"));
	size_t len = ft_printf("now let's test what it's like to [%d] printf a char [%c] more test\n", 123, 'c');
	printf("\nreturn value is : %zu\n", len);
	return (0);
}