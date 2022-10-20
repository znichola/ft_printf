/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_write_cnv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:59:59 by znichola          #+#    #+#             */
/*   Updated: 2022/10/19 09:06:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_write_cnv(t_arg *arg)
{
	int	l;

	l = 0;
	if (arg->cnv & CHR)
		l = ft_p_w_char(arg);
	else if (arg->cnv & STR)
		l = ft_p_w_str(arg);
	else if (arg->cnv & PRT)
		l = ft_p_w_ptr(arg);
	else if (arg->cnv & (DEC | INT))
		l = ft_p_w_int(arg);
	else if (arg->cnv & (USI | HEX | HES))
		l = ft_p_w_uin(arg);
	else if (arg->cnv & PCT)
		l = ft_p_wwrite(arg, &"%", 1);
	return (l);
}
