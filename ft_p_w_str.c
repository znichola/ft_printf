/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:46:52 by znichola          #+#    #+#             */
/*   Updated: 2022/11/17 12:58:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_w_str(t_arg *arg)
{
	int	l;

	if (arg->p == NULL && arg->write == TRUE)
		l = ft_p_wwrite(arg, "(null)", arg->nlen);
	else if (arg->write == TRUE)
		l = ft_p_wwrite(arg, arg->p, arg->nlen);
	else if (arg->p == NULL)
	{
		if (arg->precision == 0)
			l = 0;
		else if (arg->precision > 0 && arg->precision < 6)
			l = arg->precision;
		else
			l = 6;
		l = ft_p_wwrite(arg, "(null)", l);
	}
	else
	{
		l = ft_p_strlen(arg->p);
		if (arg->precision != UNSET && l > arg->precision)
			l = arg->precision;
	}
	return (l);
}

// int	ft_p_w_str(t_arg *arg)
// {
// 	int	l;

// 	if (arg->write == TRUE)
// 	{
// 		if (arg->p == NULL)
// 			l = ft_p_wwrite(arg, "(null)", arg->nlen);
// 		else
// 			l = ft_p_wwrite(arg, arg->p, arg->nlen);
// 	}
// 	else
// 	{
// 		if (arg->p == NULL)
// 		{
// 			if (arg->precision == 0)
// 				l = 0;
// 			else if (arg->precision > 0 && arg->precision < 6)
// 				l = arg->precision;
// 			else
// 				l = 6;
// 			l = ft_p_wwrite(arg, "(null)", l);
// 		}
// 		else
// 		{
// 			l = ft_p_strlen(arg->p);
// 			if (arg->precision != UNSET && l > arg->precision)
// 				l = arg->precision;
// 		}
// 	}
// 	return (l);
// }
