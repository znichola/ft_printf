/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_wwrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:37:29 by znichola          #+#    #+#             */
/*   Updated: 2022/10/22 15:51:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_wwrite(t_arg *arg, const void *s, int l)
{
	if (arg->write)
		write(arg->fd, s, l);
	return (l);
}
