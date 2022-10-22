/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:54:39 by znichola          #+#    #+#             */
/*   Updated: 2022/10/22 15:54:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_lldigits(unsigned int base, long long n)
{
	unsigned int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	n /= base;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	ft_count_ulldigits(unsigned int base, unsigned long long n)
{
	unsigned int	count;

	count = 1;
	n /= base;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static void	ft_rec_ull_w(unsigned int base, char *bstr, unsigned long long n)
{
	if (n > base - 1)
		ft_rec_ull_w(base, bstr, n / base);
	write(1, &bstr[n % base], 1);
	return ;
}

int	ft_p_ultoa_base_write(t_arg *arg, unsigned long n, char *bstr)
{
	int		len;
	int		base;

	base = ft_strlen(bstr);
	len = ft_count_ulldigits(base, n);
	if (arg->write)
		ft_rec_ull_w(base, bstr, n);
	return (len);
}

int	ft_ltoa_base_write(t_arg *arg, long long n, char *bstr)
{
	int				len;
	unsigned int	base;

	if (n < 0)
		n = -n;
	base = ft_strlen(bstr);
	len = ft_count_lldigits(base, n);
	if (n < 0)
		len += 1;
	if (arg->write)
		ft_rec_ull_w((unsigned long)base, bstr, n);
	return (len);
}
