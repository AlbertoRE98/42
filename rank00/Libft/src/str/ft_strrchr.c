

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	const char *last_spot;
	if (!s)
		return (NULL);
	last_spot = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_spot = s;
		s++;
	}
	if (*s == '\0')
		return ((char *)s);
	return ((char *)last_spot);
}