/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:15:45 by znichola          #+#    #+#             */
/*   Updated: 2022/11/17 12:59:23 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!(arg->precision == 0 && arg->i == 0))
		l += ft_p_ltoa_base_write(arg, (int)arg->i, DECIM);
	return (l);
}
