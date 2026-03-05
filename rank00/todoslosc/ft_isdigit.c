

#include "libft.h"

int ft_isdigit(int nbr)
{
	if (nbr >= '0' && nbr <= '9')
		return (1);
	return (0);
}