

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    /* declare 2 temporary pointer for src and dst */
    unsigned char *tmp_dst;
    unsigned char *tmp_src;
    int            counter;
    /* declare a counter */
    /* check if both src and dst are NULL */
    if (src == NULL && dst == NULL)
        return (NULL);
    /* make dst tmp pointer equal to dst converted to char * */
    /* make src tmp pointer equal to src converted to char * */
    /* if src and dst are overlapping */
        /* loop while len is greater than 0 and copy src into dst */
    /* if src and dst are not overlapping */
        /* loop while our counter is less than len and copy src into dst */
    /* return dst */
}