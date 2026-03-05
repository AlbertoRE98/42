


#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr = (unsigned char *)b;
	unsigned char value = (unsigned char)c;

	while (len > 0)
	{
		*ptr = value;
		ptr++;
		len--;
	}
	return ((void *)b);
}