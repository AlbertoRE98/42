/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:11:31 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:11:40 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * The function `ft_striteri` iterates over a string and applies a function to each character along
 * with its index.
 *
 * @param s The parameter `s` is a pointer to a character array (string) that the function
 * `ft_striteri` will iterate over.
 * @param f The parameter `f` in the `ft_striteri` function is a function pointer that points to a
 * function taking two arguments: an unsigned integer `index` and a character pointer `char*`. This
 * function is used to apply a specific operation on each character of the string `s` along
 *
 * @return The function `ft_striteri` returns `void`, as indicated by the return type `void` at the
 * beginning of the function definition.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
