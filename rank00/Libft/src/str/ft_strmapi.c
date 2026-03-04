

#include "libft.h"


char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char    		*res;
	unsigned int	tam_string;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	tam_string = ft_strlen(s);
	res = malloc(sizeof(char) * (tam_string + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (s[index])
	{
		res[index] = f(index, s[index]);
		index++;
	}
	res[index] = '\0';
	return (res);
}