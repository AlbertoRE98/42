/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:40:16 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/17 13:40:16 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(va_list *args)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		count += 5;
		return (count);
	}
	count = 0;
	write (1, "0x", 2);
	count += 2;
	count += ft_putnbr_base((unsigned long long) ptr, "0123456789abcdef");
	return (count);
}
