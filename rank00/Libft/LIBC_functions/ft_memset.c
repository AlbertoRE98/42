#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{   
    size_t index;
    unsigned char *ptr = (unsigned char *)b;
    unsigned char value = (unsigned char)c;

    index = 0;
        while (index < len)
    {
        ptr[index] = value;
        index++;
    }

    return b;
}