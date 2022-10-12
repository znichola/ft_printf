#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_count_digits(int base, long n)
{
	int	count;

	count = 1;
	if (n < 0)
		n = -n;
	n /= base;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static char	*ft_rec_itoa(int base, char *bstr, long n, char *s)
{
	if (n < 0)
	{
		n = -n;
		*s++ = '-';
	}
	if (n > base - 1)
		s = ft_rec_itoa(base, bstr, n / base, s);
	*s = bstr[n % base];
	*(++s) = '\0';
	return (s);
}

char	*ft_itoa_base(int n, char *bstr)
{
	char	*r;
	char	*ret;
	int		len;
	int		base;

	base = ft_strlen(bstr);
	len = ft_count_digits(base, n);
	if (n < 0)
		len += 1;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	r = ret;
	(void)ft_rec_itoa(base, bstr, n, r);
	return (ret);
}