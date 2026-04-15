/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 10:22:34 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/15 13:32:11 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		ft_putchar(&str[index]);
		index++;
	}
	return (index);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int					count;
	unsigned long long	base_len;

	count = 0;
	base_len = 0;
	while (base[count])
		base_len++;
	if (nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}
