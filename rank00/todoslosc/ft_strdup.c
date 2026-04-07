/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:11:10 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:11:26 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*aux;
	size_t		len;
	size_t		index;

	len = ft_strlen(s);
	aux = malloc(sizeof(char) * (len + 1));
	if (!aux)
		return (NULL);
	index = 0;
	while (s[index])
	{
		aux[index] = s[index];
		index++;
	}
	aux[index] = '\0';
	return (aux);
}
