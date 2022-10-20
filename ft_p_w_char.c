/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:34:20 by znichola          #+#    #+#             */
/*   Updated: 2022/10/19 01:52:05 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_w_char(t_arg *arg)
{
	// printf("\nneed to print a char {%c}\n", (char)arg->i);
	ft_p_wwrite(arg, &arg->i, 1);
	return(1);
}