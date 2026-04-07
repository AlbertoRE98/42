/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:07:25 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 13:07:51 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		count += 11;
		ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += 1;
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	ft_putchar(c);
	count += 1;
	return (count);
}
