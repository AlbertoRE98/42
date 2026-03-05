

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index_litle;

	index = 0;
	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[index] && index < len)
	{
		index_litle = 0;
		while (big[index + index_litle] == little [index_litle] 
					&& (index + index_litle < len))
		{
			if (little[index_litle + 1] == '\0')
				return ((char *)&big[index]);
			index_litle++;
		}
		index++;
	}
	return (NULL);
}
