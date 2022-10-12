/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bizz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:56:21 by znichola          #+#    #+#             */
/*   Updated: 2022/10/12 07:49:59 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	bizz(char **ret, const char **fmt, va_list ap)
{
	int		mask;
	size_t	i;

	mask = 0;
	i = 0;
	while (!ft_isin(*fmt[i], CNV))
	{
		// if ()
		i++;
	}
	return i;
}
