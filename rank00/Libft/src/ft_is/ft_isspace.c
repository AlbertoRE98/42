

#include "libft.h"

int ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r'
			|| c == '\n')
			return (1);
	return (0);
}