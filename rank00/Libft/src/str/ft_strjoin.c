

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char 		*res;
	size_t     	tam;
	size_t		index;
	size_t		index2;

	if (!s1 || !s2)
		return (NULL);
	tam = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (tam + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		res[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2[index2])
	{
		res[index] = s2[index2];
		index2++;
		index++;
	}
	res[index] = '\0';
	return (res);
}