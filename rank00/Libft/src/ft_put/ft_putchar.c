

#include "libft.h"

void	ft_putchar(int c)
{
	char	character;
	character = (char)c;
	write(1, &character, 1);
}
