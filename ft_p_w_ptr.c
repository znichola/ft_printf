/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:44:57 by znichola          #+#    #+#             */
/*   Updated: 2022/10/19 09:01:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_w_ptr(t_arg *arg)
{
	int	l;
	l = ft_p_wwrite(arg, "0x", 2);
	l += ft_p_ultoa_base_write(arg, (unsigned long)arg->u, HEX_S);
	return (l);
}
