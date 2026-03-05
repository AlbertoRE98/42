

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t newsize)
{
	void *newptr;

	if (!ptr)
		return (malloc(newsize));
	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	newptr = malloc(newsize);
	if (!newptr)
		return (NULL);
	if (old_size < newsize)
	{
		ft_memcpy(newptr, ptr, old_size);
	}
	else
	{
		ft_memcpy(newptr, ptr, newsize);
	}
	free(ptr);
	return (newptr);
}
