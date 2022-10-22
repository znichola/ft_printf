/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_xfix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:55 by znichola          #+#    #+#             */
/*   Updated: 2022/10/22 15:54:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_pad(t_arg *arg)
{
	int	l;
	int	i;
	int	pad;

	if (!(arg->width != UNSET && arg->nlen != UNSET && arg->zeros != UNSET))
		return (0);
	if (arg->cnv == STR)
		pad = arg->width - arg->nlen;
	else
		pad = arg->width - (arg->nlen + arg->zeros);
	l = 0;
	i = 0;
	while (i < pad)
	{
		if ((!(arg->flags & ZERO) || arg->cnv & PCT) || arg->precision != UNSET)
			l += ft_p_wwrite(arg, " ", 1);
		i++;
	}
	return (l);
}

int	ft_p_prefix(t_arg *arg)
{
	int	l;

	l = 0;
	if (!(arg->flags & MINUS))
	{
		l += ft_p_pad(arg);
	}
	if (arg->sign != UNSET && arg->cnv != STR)
	{
		l += ft_p_wwrite(arg, (char *)&arg->sign, 1);
	}
	if (arg->flags & HASH && arg->cnv & HEX && arg->u != 0)
	{
		l += ft_p_wwrite(arg, "0X", 2);
	}
	else if (arg->flags & HASH && arg->cnv & HES && arg->u != 0)
	{
		l += ft_p_wwrite(arg, "0x", 2);
	}
	return (l);
}

int	ft_p_write_padzeros(t_arg *arg)
{
	int	i;
	int	l;
	int	zeros_to_write;

	i = 0;
	l = 0;
	if (arg->zeros != UNSET)
	{
		zeros_to_write = arg->width - (arg->nlen + arg->zeros);
		if ((arg->flags & ZERO) && arg->precision > zeros_to_write)
			zeros_to_write = arg->precision;
		while (i < zeros_to_write)
		{
			l += ft_p_wwrite(arg, "0", 1);
			i++;
		}
	}
	return (l);
}

int	ft_p_write_zeros(t_arg *arg)
{
	int	i;
	int	l;

	i = 0;
	if (!arg->write && arg->zeros == UNSET && arg->nlen != UNSET)
	{
		if (arg->sign != UNSET)
			i = 1;
		else if (arg->flags & HASH && arg->u != 0)
			i = 2;
		if (arg->precision - arg->nlen + i > 0)
			l = arg->precision - arg->nlen + i;
		else
			l = 0;
	}
	else
	{
		l = 0;
		while (i < arg->zeros)
		{
			l += ft_p_wwrite(arg, "0", 1);
			i++;
		}
	}
	return (l);
}

int	ft_p_suffix(t_arg *arg)
{
	int	l;

	l = 0;
	if (arg->flags & MINUS)
		l += ft_p_pad(arg);
	return (l);
}
