/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:15:45 by znichola          #+#    #+#             */
/*   Updated: 2022/10/20 14:42:49 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// if (!arg->write)
	// 	return (0);
		
	// if (arg->cnv & (DEC | INT | USI))
	// 	d = ft_count_lldigits(10, arg->i);
	// else
	// 	d = ft_count_ulldigits(16, arg->i);
	// if ((int)arg->i < 0 && arg->cnv & (DEC | INT))
	// 	d--; // TODO:
	// t = arg->precision - d;
	// while (t > 0)
	// {
	// 	write(1, "0", 1);
	// 	t--;
	// }
	// if (arg->precision - d > 0)
	// 	return (arg->precision - d);
	// else 
	// 	return (0);

int	ft_p_w_int(t_arg *arg)
{
	size_t	l;

	l = 0;
	if ((arg->precision != UNSET && arg->zeros != UNSET) || arg->flags & ZERO)
	{
		if (!(arg->precision != UNSET))
			l += ft_p_write_padzeros(arg);
		l += ft_p_write_zeros(arg);
	}
	// printf("\ntrying to print:%d\n", (int)arg->i);
	if (!(arg->precision == 0 && arg->i == 0))
		l += ft_ltoa_base_write(arg, (int)arg->i, DECIM);
	return (l);
}