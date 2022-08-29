#include "ft_printf.h"


int main(int ac, char **av)
{
	// int	width = atoi(av[1]);
	int	num = atoi(av[2]);

	// printf("<%*d>\n", width, num);
	// printf("itoa base <%s>\n", ft_itoa_base(num, av[1]));
	ft_printf(av[1]);
}

/*
 * int	ft_printf(const char *format, ...);
 *
 *
 *  %[$][flags][width][.precision][length modifier]conversion
 *
 *
 *
 *
 *		conversion	==	c s p d i u x X %
 *		flags		==	- mak  . *
 *
 * 		CONVERSIONS
 * arg
 * 		int				d i ->		signed decimal notation
 * 		unsigned int	u x X		unsigned decimal, hexadecimal
 * 		int				c			write char
 * 		const char *	s			write string
 * 		void *			p			hexadecimal (as if by %#x or %#lx)
 *
 * 	BONUS
 *		conversion	==	nfge
 *		flags		==	l ll h hh
 *	all falgs		==  #   +		 (yes, one of them is a space)
 *
 */