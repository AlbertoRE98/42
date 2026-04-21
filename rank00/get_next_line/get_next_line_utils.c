/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:31:06 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/21 18:35:28 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*aux;
	char		charc;

	aux = s;
	charc = c;
	while (*aux)
	{
		if (*aux == charc)
			return ((char *)aux);
		aux++;
	}
	if (charc == '\0')
		return ((char *)aux);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*resultado;
	size_t	index;
	size_t	index2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(""));
	if (!s2)
		return (ft_strdup(s1));
	resultado = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen (s2) + 1));
	if (!resultado)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		resultado[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2[index2])
		resultado[index++] = s2[index2++];
	resultado[index] = '\0';
	free(s1);
	return (resultado);
}
