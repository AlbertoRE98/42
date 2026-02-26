

#include "libft.h"

static int is_sep(char c, const char delimit)
{
	if (c == delimit)
		return (1);
	return (0);
}
int ft_count_words(char const *str, const char delim)
{
	int counter;
	int inside_word;
	int index;

	index = 0;
	inside_word = 0;
	counter = 0;

	while (str[index])
	{
		if(inside_word == 0 && !is_sep(str[index], delim))
		{
			inside_word = 1;
			counter++;
		}
		else if (is_sep(str[index], delim))
		{
			inside_word = 0;
		}
		index++;
	}
	return (counter);
}