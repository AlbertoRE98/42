/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:02:51 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:03:05 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*aux_str;
	unsigned char		uc;

	uc = c;
	aux_str = (unsigned char *)s;
	if (!s)
		return (NULL);
	while (n > 0)
	{
		if (*aux_str == uc)
			return ((void *)aux_str);
		aux_str++;
		n--;
	}
	return (NULL);
}
