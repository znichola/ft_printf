/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_uin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:49:12 by znichola          #+#    #+#             */
/*   Updated: 2022/10/22 16:02:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_w_uin(t_arg *arg)
{
	int	l;

	l = 0;
	if ((arg->precision != UNSET && arg->zeros != UNSET) || arg->flags & ZERO)
	{
		if (!(arg->precision != UNSET))
			l += ft_p_write_padzeros(arg);
		l += ft_p_write_zeros(arg);
	}
	if ((arg->precision == 0 && arg->u == 0))
		return (l);
	if (arg->cnv & USI)
		l += ft_p_ultoa_base_write(arg, arg->u, DECIM);
	else if (arg->cnv & HES)
		l += ft_p_ultoa_base_write(arg, arg->u, HEX_S);
	else if (arg->cnv & HEX)
		l += ft_p_ultoa_base_write(arg, arg->u, HEX_X);
	return (l);
}
