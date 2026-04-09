/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:54:07 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/09 09:57:46 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, const char delimit)
{
	if (c == delimit)
		return (1);
	return (0);
}

int	ft_count_words(char const *str, const char delim)
{
	int		counter;
	int		inside_word;
	int		index;

	index = 0;
	inside_word = 0;
	counter = 0;
	while (str[index])
	{
		if (inside_word == 0 && !is_sep(str[index], delim))
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
