/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dlim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:08:44 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:08:57 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_split_dlim` takes a string and delimiters as input, splits the string into words
 * based on the delimiters, and returns an array of strings representing the words.
 *
 * @param c The `c` parameter in the `is_delimiter` function represents a character that we are
 * checking to see if it is a delimiter or not. Delimiters are characters that separate words in a
 * string.
 * @param delimiters The `delimiters` parameter in the provided code refers to a string containing
 * characters that are considered as delimiters for splitting the input string `s` into words. These
 * delimiters are used to determine where one word ends and the next word begins in the input string.
 *
 * @return The `ft_split_dlim` function returns a dynamically allocated array of strings (char
 * pointers) that represent the words extracted from the input string `s` based on the provided
 * delimiters.
 */
static int	is_delimiter(char c, char const *delimiters)
{
	size_t	i;

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

static size_t	count_words(char const *s, char const *delimiters)
{
	size_t	count;
	size_t	i;
	int		in_word;

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

static char	*extract_word(char const *s, char const *delimiters, size_t *pos)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

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

static void	free_memory(char **res, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split_dlim(char const *s, char const *delimiters)
{
	char	**res;
	size_t	nwords;
	size_t	position;
	size_t	index;

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
