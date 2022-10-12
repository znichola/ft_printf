/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bang.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:24:33 by znichola          #+#    #+#             */
/*   Updated: 2022/10/12 11:00:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	bang(char **ret, const char **fmt)
{
	size_t	i;

	i = 0;
	while (*fmt[i] != '\0' && *fmt[i] != '%')
		i++;
	ret = (char **)malloc(sizeof(char) + (i + 1));
	if (!ret)
		return (NULL);
	while (--i > 0)
	{
		printf("fmt <%c>\n", *fmt[i]);
		*ret[i] = *fmt[i];
	}
		// i++;
	// write(1, *fmt, i);
	return (i);
}