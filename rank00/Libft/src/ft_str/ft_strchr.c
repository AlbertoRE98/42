/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:10:50 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:10:52 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
