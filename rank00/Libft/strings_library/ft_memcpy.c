

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char       *temp_destiny;
	unsigned char 		*temp_source;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	temp_destiny = (unsigned char *)dst;
    temp_source = (const unsigned char *)src;
    
    while (n--)
        *(temp_destiny++) = *(temp_source++);
	return (dst);
}