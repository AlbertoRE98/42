

#include "libft.h"

static char *extract_word(const char *s, char c, size_t *pos)
{
	char    *res;
	size_t  start;
	size_t  end;
	size_t  i;
	
	while (s[*pos] && s[*pos] == c)
		(*pos)++;
	
	start = *pos;
	while (s[*pos] && s[*pos] != c)
		(*pos)++;
	
	end = *pos;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

static void free_memory(char **res, size_t count)
{
    size_t i;
    
    i = 0;
    while (i < count)
    {
        free(res[i]);
        i++;
    }
    free(res);
}
char		**ft_split(char const *s, char c)
{
	char    **res;
	size_t  nwords;
	size_t	index;
	size_t	pos;

	if (!s)
		return (NULL);
	pos = 0;
	nwords = ft_count_words(s, c);
	res = malloc (sizeof (char *) * (nwords + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (index < nwords)
	{
		res[index] = extract_word(s,c,&pos);
		if (!res[index])
		{
			free_memory(res,index);
			return (NULL);
		}
		index++;
	}
	res[index] = NULL;
	return (res);
}
