/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 08:16:04 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/16 08:16:04 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	return (ft_putchar((char)va_arg(*args, int)));
}

int	ft_print_str(va_list *args)
{
	return (ft_putstr(va_arg(*args, char *)));
}
