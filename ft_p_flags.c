/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:59:00 by znichola          #+#    #+#             */
/*   Updated: 2022/11/17 12:57:51 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// - + # 0 . ' '
void	ft_p_falgs(t_arg *arg, const char **fmt)
{
	while (ft_p_isin(**fmt, FLG))
	{
		arg->flags = arg->flags | (1U << (**fmt - 32));
		(*fmt)++;
	}
	return ;
}
