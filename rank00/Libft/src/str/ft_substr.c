

#include "libft.h"

static size_t	calculate_len(size_t s_len, unsigned int start, size_t len)
{
	if (start >= s_len)
		return (0);
	if (len > s_len - start)
		return (s_len - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	c_len;

	if (!s)
		return (NULL);
	c_len = calculate_len(ft_strlen(s), start, len);
	res = malloc(sizeof(char) * (c_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < c_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
