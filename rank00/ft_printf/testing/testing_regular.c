/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_regular.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:37:21 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/17 16:37:21 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len1, len2;

	printf("--- Test Comparativo ---\n");
	// Caracteres y Strings
	len1 = ft_printf("Mio: %c, %s\n", 'A', "Hola Mundo");
	len2 = printf("Ori: %c, %s\n", 'A', "Hola Mundo");
	printf("Lengths: Mio[%d] | Ori[%d]\n\n", len1, len2);
	// Enteros y Unsigned
	len1 = ft_printf("Mio: %d, %i, %u\n", -123, 42, 4294967295U);
	len2 = printf("Ori: %d, %i, %u\n", -123, 42, 4294967295U);
	printf("Lengths: Mio[%d] | Ori[%d]\n\n", len1, len2);
	// Hexadecimales
	len1 = ft_printf("Mio: %x, %X, %%\n", 255, 255);
	len2 = printf("Ori: %x, %X, %%\n", 255, 255);
	printf("Lengths: Mio[%d] | Ori[%d]\n\n", len1, len2);
	// Punteros
	void *ptr = &len1;
	len1 = ft_printf("Mio: %p, %p\n", ptr, NULL);
	len2 = printf("Ori: %p, %p\n", ptr, NULL);
	printf("Lengths: Mio[%d] | Ori[%d]\n\n", len1, len2);

	return (0);
}
