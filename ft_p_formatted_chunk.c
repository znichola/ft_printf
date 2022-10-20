/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_formatted_chunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:34:54 by znichola          #+#    #+#             */
/*   Updated: 2022/10/20 14:39:59 by znichola         ###   ########.fr       */
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

static void ft_p_calculate_nlen(t_arg *arg)
{
	int foo = 0;
	// arg->nlen = 0;
	arg->write = FALSE;
	
	// printf("\nnlen->starting:%d\n", arg->nlen);
	foo = ft_p_prefix(arg);
	// printf("\nnlen->prefix:%d\n", foo);
	foo += ft_p_write_cnv(arg);
	// printf("\nnlen->prefix+cnv:%d\n", foo);
	arg->nlen = foo;
	arg->zeros = ft_p_write_zeros(arg);
	// printf("\nno goo zero:%d", arg->zeros);
	// printf("\nnlen->prefix+cnv:%d\n", arg->nlen);
	// arg->nlen += ft_p_write_cnv(arg);
	// if (arg->cnv & STR && arg->precision != UNSET)
	// {
	// 	printf("\nsdfds nlen%d\n", arg->nlen);
	// 	if (arg->nlen > arg->precision) //TODO finish this function!!!
	// 	{
	// 		// printf("\nkjsdhfkjhfsd:%d\n", arg->nlen);
	// 		arg->nlen = arg->precision;
	// 	}
	// }
	/*

	if (arg->sign)
		arg->nlen = 1;
	// if (arg->flags & (PLUS | SPACE) && (int)arg->i >= 0 && arg->cnv & (INT | DEC))
	// 	arg->nlen = 1;
	else if (((arg->flags & HASH && arg->i != 0) && arg->cnv & (HES | HEX)) || arg->cnv & PRT)
		arg->nlen = 2;
	// printf("\nwerwer %d\n", arg->nlen);
	// printf("\nsldkjflsdk%d", arg->cnv);
	if (arg->cnv & (PRT | DEC | INT | USI | HES | HEX))
	{
		// printf("\ncalculating nlen but counting digits i:%ju cnv:%d nlen%d\n", arg->i, arg->cnv, ft_count_lldigits(10, arg->i));
		// printf("\ncalculating nlen but counting digits i:%ju cnv:%d nlen%d\n", arg->i, arg->cnv, ft_count_ulldigits(16, arg->i));
		if (arg->cnv & (DEC | INT | USI))
			arg->nlen += ft_count_lldigits(10, arg->i);	// remember to not forget the minus!
		else
			arg->nlen += ft_count_ulldigits(16, arg->i);
	}
	else
	{
		if (arg->cnv & CHR)
			arg->nlen = 1;
		else if (arg->cnv & STR && arg->p == NULL)
			arg->nlen = 6;
		else if (arg->cnv & STR)
			arg->nlen = ft_strlen(arg->p);
	} */
	// if (arg->width > 0 && arg->nlen < arg->width)
	// 	arg->nlen = arg->width - arg->nlen;
	// printf("\nnlen%d\n", arg->nlen);
}

static void ft_p_cnv(t_arg *arg, const char **fmt)
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
	(*fmt)++;
}

static void ft_p_sign(t_arg *arg)
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
		ft_putstr_fd("\nformat string error\n", 1);
	ft_p_cnv(&arg, fmt);
	ft_p_specifier(&arg, ap);
	ft_p_sign(&arg);
	ft_p_calculate_nlen(&arg);
	// printf("\nzeros:%d\n", arg.zeros);
	// return 1;
	arg.write = TRUE;
	return (ft_p_prefix(&arg)
		+ ft_p_write_cnv(&arg)
		+ ft_p_suffix(&arg));
}
