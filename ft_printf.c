/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:20:54 by znichola          #+#    #+#             */
/*   Updated: 2022/12/02 15:34:50 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintfd(int fd, const char *format, va_list *ap)
{
	int		count;
	int		c;

	fd = 1;
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			c = ft_p_formatted_chunk(fd, &format, ap);
		}
		else
		{
			c = ft_p_str_chunk(fd, &format);
		}
		if (c < 0)
			return (-1);
		count += c;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vprintfd(1, format, &ap);
	va_end(ap);
	return (count);
}

int	ft_printfd(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vprintfd(fd, format, &ap);
	va_end(ap);
	return (count);
}

int	ft_debug_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	if (DEBUG_TEST)
	{
		va_start(ap, format);
		count = ft_vprintfd(fd, format, &ap);
		va_end(ap);
		return (count);
	}
	return (0);
}