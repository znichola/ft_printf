/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:21:08 by znichola          #+#    #+#             */
/*   Updated: 2022/10/13 12:21:08 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>

//  allowed funcs
// malloc, free, write, va_start, va_arg, va_copy, va_end

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define DECIM	"0123456789"
# define HEX_x	"0123456789abcdef"
# define HEX_X	"0123456789ABCDEF"
# define CNV	"cspdiuxX%"
# define FLG	"-+#0. "

/* Modidifer flangs as big representatoin, see the musl implementaion*/

////// START with a %
// # define HASH	(1U << 0) // alternate form for x X conversion
// # define ZERO	(1U << 1) // 0 padding for all converions. if presicion is given ignore
// # define MINUS	(1U << 2) // the value is to be left adjusted
// # define SPACE	(1U << 3) // a blank left before signed conversion
// # define PLUS	(1U << 4) // always place sign before numer, overrides space is both used
// apostrof, not manditory but cool, seperates nums into groups of 3
// MANDETORY optional decimal number for minimum field width etc
// # define PERIOD	(1U << 5) // a period followed by optional digic string for min number of digits to appear or max character printed
// optional length modifier l ll etc. 
////// END with a character that spesifies the converion type

// %[flags][width][.precision][length]specifier 

// # define SPACE	(1U << (' ' - 32))
// # define HASH	(1U << ('#' - 32))
// # define PLUS	(1U << ('+' - 32))
// # define MINUS	(1U << ('-' - 32))
// # define PERIOD	(1U << ('.' - 32))
// # define ZERO	(1U << ('0' - 32))

// # define FLAG_MASK (SPACE | HASH | PLUS | MINUS | PERIOD | ZERO)

# define SPACE	1U
# define HASH	8U
# define PLUS	2048U
# define MINUS	8192U
# define PERIOD	16384U		// 00100000000000000
# define ZERO	65536U		// 10000000000000000
# define FLAG_MASK 92169U	// 10110100000001001

# define CHR	(1UL << 'c' - 'X')
# define STR	(1UL << 's' - 'X')
# define PTR	(1UL << 'p' - 'X')
# define DEC	(1UL << 'd' - 'X')
# define INT	(1UL << 'i' - 'X')
# define USI	(1UL << 'u' - 'X')
# define HEx	(1UL << 'x' - 'X')
# define HEX	(1UL << 'X' - 'X')

# define CNV_MASK (CHR | STR | PRT | DEC | INT | USI | HEx | HEX)

// # define TEST 0b00001000

int		ft_isin(char c, char *s);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(int n, char *bstr);
size_t	ft_formatted_chunk(const char **fmt, va_list ap);
size_t	ft_raw_chunk(const char **fmt);


// libft func duplicates
size_t	ft_strlen(const char *s);

#endif /* ft_printf_h */
