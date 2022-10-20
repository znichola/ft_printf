/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:46:52 by znichola          #+#    #+#             */
/*   Updated: 2022/10/20 14:39:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_w_str(t_arg *arg)
{
	int	l;
	
	if (arg->write == TRUE)
	{
		if (arg->p == NULL)
			l = ft_p_wwrite(arg, "(null)", arg->nlen);
		else
			l = ft_p_wwrite(arg, arg->p, arg->nlen);	
	}
	else
	{
		if (arg->p == NULL)
		{
			// printf("\nrinitng NULL\n");
			if (arg->precision == 0)
				l = 0;
			else if (arg->precision > 0 && arg->precision < 6)
				l = arg->precision;
			else
				l = 6;
			l = ft_p_wwrite(arg, "(null)", l);
			// printf("\nnullpsnt:%d\n", l);
		}
		else 
		{
			l = ft_strlen(arg->p);
			// printf("\nnlen:%d width:%d\n", arg->nlen, arg->width);
			if (arg->precision != UNSET && l > arg->precision) //TODO: linked to this! 
				l = arg->precision;//l = arg->precision;
		}
	}
	return (l);
}	
	// if (!arg->write)
	// 	l = ft_strlen(arg->p);
	// if (arg->p == NULL)
	// {
	// 	if (arg->precision > 0 && arg->precision < 6)
	// 		l = arg->precision;
	// 	else
	// 		l = 6;
	// 	l = ft_p_wwrite(arg, "(null)", l);
	// }
	// else 
	// {
	// 	printf("\nnlen:%d width:%d\n", arg->nlen, arg->width);
	// 	if (arg->precision != UNSET && l > arg->precision) //TODO: linked to this! 
	// 	{
	// 		l = arg->precision;//l = arg->precision;
	// 	}
	// 	else
	// 		l = ft_strlen(arg->p);
	// 	l = ft_p_wwrite(arg, arg->p, l);
	// }
	// printf("\nnlen is:%d\n", arg->nlen);
	// l = ft_p_wwrite(arg, arg->p, arg->nlen);
	
