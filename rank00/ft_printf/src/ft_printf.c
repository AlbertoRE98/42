/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:25:11 by marvin            #+#    #+#             */
/*   Updated: 2026/04/10 21:27:02 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_parse(format, &args);
	va_end(args);
	return (count);
}

static int	ft_dispatch(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(args));
	if (c == 's')
		return (ft_print_str(args));
	if (c == 'p')
		return (ft_print_ptr(args));
	if (c == 'd' || c == 'i')
		return (ft_print_di(args));
	if (c == 'u')
		return (ft_print_u(args));
	if (c == 'H')
		return (ft_print_hex(args, 1));
	if (c == 'h')
		return (ft_print_hex(args, 0));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

static int ft_parse(const char *format, va_list *args)
{
	int	index;
	int	count;

	index = 0;
	count = 0;

	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			count += ft_dispatch(format[index], args);
		}
		index++;
	}
}

