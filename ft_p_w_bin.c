/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_w_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:33:48 by znichola          #+#    #+#             */
/*   Updated: 2022/10/31 13:56:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/*
 *prints binary format numbers. 
 */

int	ft_p_loop_bin(t_arg *arg)
{
	unsigned	n;
	int			l;
	int			d;
	
	d = 0;
	l = 0;
	n = arg->u;
	// while ((n = (n > 1U)) > 0)
	while (n > 0 || (arg->precision > d))
	{
		// printf("\n%lu, n:%u\n", arg->u, n);
		// return (0);
		if (n & (1U << 8))
			l += ft_p_wwrite(arg, "1", 1);
		l += ft_p_wwrite(arg, "0", 1);
		d++;
		if (d % 4 == 0)
			l += ft_p_wwrite(arg, " ", 1);
		n = n << 1U;
	}
	return (l);
}

int	ft_p_rec_bin(unsigned int n, t_arg *arg)
{
	int	l;

	l = 0;
	if (n > 1)
		l += ft_p_rec_bin(n / 2, arg) + 1;
	if (arg->write == TRUE)
	{
		if (arg->precision == 0)
		{
			// printf("\nl%d\n", l);
			if (l % 4 == 0 && l != 0)
				l += write(1, &" ", 1);
			l += write(1, &"01"[n % 2], 1);
		}
	}
	return (l);
}
// int b = 0b111011;
int	ft_p_w_bin(t_arg *arg)
{
	int	l;
	
	l = 0;
	// if (arg->flags & HASH)
	// {
	// 	// printf("\nhere\n");
	// }
	// printf("len:%d\n", ft_p_rec_bin(arg->u));
	l += ft_p_loop_bin(arg);
	// l += ft_p_rec_bin(arg->u, arg);
	// l += ft_p_ultoa_base_write(arg, arg->u, "01");
	// else if ()
	// printf("len is:%d", l);
	return (l);
}