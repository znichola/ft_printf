/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_str_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:31:34 by znichola          #+#    #+#             */
/*   Updated: 2022/10/18 22:59:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_str_chunk(int fd, const char **fmt)
{
	int	i;

	i = 0;
	while ((*fmt)[i] != '\0' && (*fmt)[i] != '%')
		i++;
	write(fd, *fmt, i);
	*fmt += i;
	return (i);
}