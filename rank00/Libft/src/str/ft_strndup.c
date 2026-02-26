

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t  index;
	size_t	len;

	if (!s)
		return (NULL);
	len  = ft_strlen(s);
	if (n > len)
		res = malloc(sizeof(char) * (len + 1));
	else
		res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (s[index] && index < n)
	{
		res[index] = s[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}