/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:32:19 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/16 16:32:19 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_di(va_list *args)
{
	long long int	n;
	int				count;

	n = (long long int)va_arg(*args, int);
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	count += ft_putnbr_base(n, "0123456789");
	return (count);
}

int ft_print_hex(va_list *args, int uppercase)
{
	unsigned int	n;

	n = (unsigned int) va_arg(*args, unsigned int);
	if (uppercase)
		return (ft_putnbr_base((unsigned long long) n, "0123456789ABCDEF"));
	return (ft_putnbr_base((unsigned long long) n, "0123456789abcdef"));
}

int ft_print_u(va_list *args)
{
	unsigned int	nbr;

	nbr = va_arg(*args, unsigned int);
	return (ft_putnbr_base((unsigned long long) nbr, "0123456789"));
}
