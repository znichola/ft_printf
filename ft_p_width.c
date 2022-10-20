/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:59:44 by znichola          #+#    #+#             */
/*   Updated: 2022/10/18 23:17:09 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// [width] the minimum space it should take
void	ft_p_width(t_arg *arg, const char **fmt)
{
	while (ft_isdigit(**fmt))
	{
		arg->width = arg->width * 10 + **fmt - '0';
		(*fmt)++;
	}
	return ;
}
