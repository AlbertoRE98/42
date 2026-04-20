/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:04:35 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:04:38 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp_destiny;
	const unsigned char	*temp_source;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	temp_destiny = (unsigned char *)dst;
	temp_source = (const unsigned char *)src;
	while (n--)
	{
		*(temp_destiny++) = *(temp_source++);
	}
	return (dst);
}
