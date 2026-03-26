

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*aux;
	char		charc;

	aux = s;
	charc = c;
	while (*aux)
	{
		if (*aux == charc)
			return ((char *)aux);
		aux++;
	}
	if (charc == '\0')
		return ((char *)aux);
	return (NULL);
}
