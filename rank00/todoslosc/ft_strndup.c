/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:12:39 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:12:42 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	index;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
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
