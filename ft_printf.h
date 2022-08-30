#ifndef ft_printf_h
#define FT_PRINT_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>

//  allowed funcs
// malloc, free, write, va_start, va_arg, va_copy, va_end

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define DECIM	"0123456789"
# define HEX_x	"0123456789abcdef"
# define HEX_X	"0123456789ABCDEF"
# define CNV	"cspdiuxX"
# define FLG	"-0.*"

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(int n, char *bstr);

#endif /* ft_printf_h */
