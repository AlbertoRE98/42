/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:13:17 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:13:29 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_spot;
	char		charc;

	charc = (char)c;
	last_spot = NULL;
	while (*s)
	{
		if (*s == charc)
			last_spot = s;
		s++;
	}
	if (charc == '\0')
		return ((char *)s);
	return ((char *)last_spot);
}
