

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *aux_s1;
	const unsigned char *aux_s2;
	size_t				counter;

	aux_s1 = (const unsigned char *)s1;
	aux_s2 = (const unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (*aux_s1 != *aux_s2)
			return (*aux_s1 - *aux_s2);
		aux_s1++;
		aux_s2++;
		counter++;
	}
	return (0);
}