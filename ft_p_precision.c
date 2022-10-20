/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:59:24 by znichola          #+#    #+#             */
/*   Updated: 2022/10/18 23:16:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_precision(t_arg *arg, const char **fmt)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		arg->precision = 0;
		while (ft_isdigit(**fmt))
		{
			arg->precision = arg->precision * 10 + **fmt - '0';
			(*fmt)++;
		}
	}
	return ;
}
