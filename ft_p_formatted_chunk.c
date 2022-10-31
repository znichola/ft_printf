/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_formatted_chunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:34:54 by znichola          #+#    #+#             */
/*   Updated: 2022/10/31 10:47:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_p_initargs(t_arg *arg)
{
	arg->i = 0;
	arg->p = NULL;
	arg->flags = 0;
	arg->width = 0;
	arg->precision = UNSET;
	arg->sign = UNSET;
	arg->write = FALSE;
	arg->nlen = UNSET;
	arg->zeros = UNSET;
}

static void	ft_p_calculate_nlen(t_arg *arg)
{
	int	foo;

	arg->write = FALSE;
	foo = ft_p_prefix(arg);
	foo += ft_p_write_cnv(arg);
	arg->nlen = foo;
	arg->zeros = ft_p_write_zeros(arg);
}

static void	ft_p_cnv(t_arg *arg, const char **fmt)
{
	if (**fmt == 'c')
		arg->cnv = 1U << 1;
	else if (**fmt == 's')
		arg->cnv = 1U << 2;
	else if (**fmt == 'p')
		arg->cnv = 1U << 3;
	else if (**fmt == 'd')
		arg->cnv = 1U << 4;
	else if (**fmt == 'i')
		arg->cnv = 1U << 5;
	else if (**fmt == 'u')
		arg->cnv = 1U << 6;
	else if (**fmt == 'x')
		arg->cnv = 1U << 7;
	else if (**fmt == 'X')
		arg->cnv = 1U << 8;
	else if (**fmt == '%')
		arg->cnv = 1U << 9;
	else if (**fmt == 'b')
		arg->cnv = 1U << 10;
	(*fmt)++;
}

static void	ft_p_sign(t_arg *arg)
{
	if (arg->cnv & (DEC | INT) && (int)arg->i < 0)
	{
		arg->sign = '-';
		arg->i = -arg->i;
	}
	else if (arg->flags & PLUS)
		arg->sign = '+';
	else if (arg->flags & SPACE)
		arg->sign = ' ';
}

// %[flags][width][.precision][length]specifier
int	ft_p_formatted_chunk(int fd, const char **fmt, va_list *ap)
{
	t_arg	arg;

	(*fmt)++;
	arg.fd = fd;
	ft_p_initargs(&arg);
	ft_p_falgs(&arg, fmt);
	ft_p_width(&arg, fmt);
	ft_p_precision(&arg, fmt);
	if (!ft_isin(**fmt, CNV))
		ft_p_wwrite(&arg, "\nformat string error\n", 23);
	ft_p_cnv(&arg, fmt);
	ft_p_specifier(&arg, ap);
	ft_p_sign(&arg);
	ft_p_calculate_nlen(&arg);
	arg.write = TRUE;
	return (ft_p_prefix(&arg)
		+ ft_p_write_cnv(&arg)
		+ ft_p_suffix(&arg));
}
