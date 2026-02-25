

#include "libft.h"

long long	ft_atoll(const char *ptr)
{
	const char		    *tmp;
	int			         sign;
	long long int   	res;

	res = 0;
	sign = 1;
	tmp = ptr;
	if (!tmp)
		return (0);
	while (ft_isspace(*tmp) && tmp)
		tmp++;
	if (*tmp == '-' || *tmp == '+')
	{	
		if (*tmp == '-')
			sign *= -1;
		tmp++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		res = (res * 10) + (*tmp - '0');
		tmp++;
	}
	return (res * sign);
}
