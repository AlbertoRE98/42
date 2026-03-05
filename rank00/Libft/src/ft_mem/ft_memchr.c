

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *aux_str;
	unsigned char		uc;

	uc = c;
	aux_str = (const unsigned char *)s;
	while (n > 0)
	{
		if(*aux_str == uc)
			return (aux_str);
		aux_str++;
		n--;
	}
	return (NULL);
}