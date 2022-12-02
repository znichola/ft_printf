/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:59:32 by znichola          #+#    #+#             */
/*   Updated: 2022/12/02 15:38:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// c s p d i u x X %
int	ft_p_specifier(t_arg *arg, va_list *ap)
{
	if (arg->cnv & CHR)
		arg->i = (signed char)va_arg(*ap, int);
	else if (arg->cnv & STR)
		arg->p = va_arg(*ap, void *);
	else if (arg->cnv & PRT)
		arg->u = (unsigned long)va_arg(*ap, void *);
	else if (arg->cnv & (DEC | INT))
		arg->i = va_arg(*ap, int);
	else if (arg->cnv & (USI | HEX | HES))
		arg->u = va_arg(*ap, unsigned int);
	return (SUCCESS);
}
