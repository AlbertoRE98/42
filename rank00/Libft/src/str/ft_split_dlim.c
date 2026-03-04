

#include "libft.h"

static int is_delimiter(char c, char const *delimiters)
{
	size_t i;
	
	if (!delimiters)
		return (0);
	i = 0;
	while (delimiters[i])
	{
		if (delimiters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t count_words(char const *s, char const *delimiters)
{
	size_t count;
	size_t i;
	int    in_word;
	
	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (!is_delimiter(s[i], delimiters) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delimiter(s[i], delimiters))
			in_word = 0;
		i++;
	}
	return (count);
}

static char *extract_word(char const *s, char const *delimiters, size_t *pos)
{
	char    *res;
	size_t  start;
	size_t  end;
	size_t  i;
	
	while (s[*pos] && is_delimiter(s[*pos], delimiters))
		(*pos)++;
	start = *pos;
	while (s[*pos] && !is_delimiter(s[*pos], delimiters))
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

char **ft_split_dlim(char const *s, char const *delimiters)
{
	char    **res;
	size_t  nwords;
	size_t  position;
	size_t  index;

	if (!s || !delimiters)
		return (NULL);
	position = 0;
	nwords = count_words(s, delimiters);
	res = malloc(sizeof(char *) * (nwords + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (index < nwords)
	{
		res[index] = extract_word(s, delimiters, &position);
		if (!res[index])
		{
			free_memory(res, index);
			return (NULL);
		}
		index++;
	}
	res[index] = NULL;
	return (res);
}
