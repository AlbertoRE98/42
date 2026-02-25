

#include "libft.h"


char		*ft_strdup(const char *s)
{
	char 		*aux;
	size_t			len;
	size_t		index;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	aux = malloc(sizeof(char) * (len + 1));
	if (!aux)
		return (NULL);
	index = 0;
	while (s[index])
	{
		aux[index] = s[index];
		index++;
	}
	aux[index] = '\0';
	return (aux);
}