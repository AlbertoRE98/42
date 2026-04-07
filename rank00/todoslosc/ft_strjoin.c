/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:11:45 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:11:48 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		index;
	size_t		index2;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		res[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2[index2])
	{
		res[index] = s2[index2];
		index2++;
		index++;
	}
	res[index] = '\0';
	return (res);
}
