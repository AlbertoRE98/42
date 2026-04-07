/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:02:02 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:02:44 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*aux_dest;
	const unsigned char	*aux_src;
	size_t				index;
	unsigned char		ucaux;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	ucaux = (unsigned char)c;
	aux_dest = (unsigned char *)dest;
	aux_src = (const unsigned char *)src;
	index = 0;
	while (index++ < n)
	{
		*aux_dest = *aux_src;
		if (*aux_dest == ucaux)
			return (aux_dest + 1);
		aux_dest++;
		aux_src++;
	}
	return (NULL);
}
