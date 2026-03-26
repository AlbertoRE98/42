

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *aux_str;
	unsigned char uc;

	uc = c;
	aux_str = (unsigned char *)s;
	if (!s)
		return (NULL);
	while (n > 0)
	{
		if (*aux_str == uc)
			return ((void *)aux_str);
		aux_str++;
		n--;
	}
	return (NULL);
}