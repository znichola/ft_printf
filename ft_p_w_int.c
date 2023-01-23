/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:15:45 by znichola          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:31 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_w_int(t_arg *arg)
{
	size_t	l;

	l = 0;
	if ((arg->precision != UNSET && arg->zeros != UNSET)
		|| arg->flags & FT_ZERO)
	{
		if (!(arg->precision != UNSET))
			l += ft_p_write_padzeros(arg);
		l += ft_p_write_zeros(arg);
	}
	if (!(arg->precision == 0 && arg->i == 0))
		l += ft_p_ltoa_base_write(arg, (int)arg->i, DECIM);
	return (l);
}
