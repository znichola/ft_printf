/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatted_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:56:21 by znichola          #+#    #+#             */
/*   Updated: 2022/10/13 16:21:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagmask(const char **fmt)
{
	// runthrough and record the flags found, throw an error when it's bad.
	// leave error for later
	size_t	i;
	int		mask;

	i = 0;
	mask = 0;
	while (ft_isin( (*fmt)[i], CNV))
	{
		mask = mask | (1U << ((*fmt)[i++] - 32));
	}
	return (mask);
}

// %[flags][width][.precision][length]specifier 

size_t	ft_conversions(int mask, const char cnv, va_list ap)
{
	size_t	len;

	if (cnv == 'c')
		len = ft_print_char(mask, va_arg(ap, int));
	else if (cnv == 's')
		len = ft_print_string(mask, va_arg(ap, const char *)); // const char *	s			write string
	else if (cnv == 'p')
		len = ft_print_pointer(mask, va_arg(ap, void *));
	else if (cnv == 'd' || cnv == 'i')
		len = ft_print_signed_int(mask, va_arg(ap, int));
	else if (cnv == 'u')
		len = ft_print_unsigned_decimal(mask, va_arg(ap, unsigned int));
	else if (cnv == 'x' || cnv == 'X')
		len = ft_print_unsigned_hex(mask, va_arg(ap, unsigned int));
	else
		// format error message
	return (len);
}

// %[flags][width][.precision][length]specifier 
size_t	ft_formatted_chunk(const char **fmt, va_list ap)
{
	int		mask;
	int		width;
	size_t	i;
	size_t	len;

	char foo[10];
	
	len = 0;
	mask = 0;
	i = 1;







	
	while (ft_isin((*fmt)[i], FLG))
	{
		// printf("doing a flag check\n");
		mask = ft_flagmask(fmt);
		i++;
	}
	width = ft_atoi((*fmt)[i]);
	while ()
	while (ft_isin((*fmt)[i], CNV))
	{
		printf("checking what the print type it is.\n");
		// printf("\npost incrament fmt char is <%c>\n", (*fmt)[i]);
		i++;
	}
	if (i == 1)
	{
		// printf("error, invalid formating type");
	}
	(*fmt) += i;
	// glorb(mask);
	return (i);
}
