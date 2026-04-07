/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:04:46 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:05:20 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	if (dst < src)
	{
		while (len--)
			*(tmp_dst++) = *(tmp_src++);
	}
	else if (dst > src)
	{
		tmp_dst += len;
		tmp_src += len;
		while (len--)
			*(--tmp_dst) = *(--tmp_src);
	}
	return (dst);
}
