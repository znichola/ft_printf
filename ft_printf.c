/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:21:39 by znichola          #+#    #+#             */
/*   Updated: 2022/10/12 10:52:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// takes the format string and returns a chunk of string that needs to be printed.
//	it modifes the format string pointer to point to the next character
// size_t	foo(char **ret, char **fmt)
// {
// 	size_t		len;

// 	len = 0;
// 	if (*fmt[0] != '%')
// 	{
// 		while (*fmt[len] != '%')
// 			*ret[len] = *fmt[len++];
// 		reutrn(len);
// 	}
// 	len = bar(ret, fmt);
// 	return (len);
// }

// size_t	bizz(char **ret, char **fmt, va_list ap)
// {
// 	// start of a chunk of format information, ends with CNV
// }

// size_t	bang(char **ret, char **fmt)
// {
// 	// start of a regular chunk of text.
// }

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*tmp;
	size_t	c;
	size_t	count;

	va_start(ap, format);
	count = 0;
	printf("here printing <%s>\n", format);
	while (*format)
	{
		if (*format == '%')
		{
			c = bizz(&tmp, &format, ap);
		}
		else
		{
			printf("hereasd\n");
			c = bang(&tmp, &format);
			printf("inside bang! c <%zu>\n", c);
		}	
		count += c;
		write (1, tmp, c);
		free(tmp);
	}
	return (count);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	ft_printf("hello this is a %cregular test");
	return (0);
}