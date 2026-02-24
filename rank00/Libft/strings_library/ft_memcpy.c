

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char       *temp_destiny;
	const unsigned char *temp_source;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	if (n == 0)
		return (dst);
		temp_destiny = (unsigned char*) dst;
		temp_source = (unsigned char*) src;
		while (n > 0)
		{
			*(temp_destiny++) = *(temp_source++);
			n--;
		}
	return (dst);
}