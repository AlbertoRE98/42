
#include "libft.h"

int	ft_putnbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		count += 11;
        ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += 1;
        ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
    ft_putchar(c);
	count += 1;
	return (count);
}
