/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:22:20 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/10 14:22:20 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/*
FUNCION PRINCIPAL NECESARIA
*/
int ft_printf(char const *format, ...);

/*
FUNCIONES DE UTILIDAD PARA ESCRITURA
*/
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr_base(unsigned long long nbr, char *base);

/*
ESQUELETO Y FUNCIONES A LLAMAR PARA CONVERTIR Y PARSEAR
PARTIMOS DE UN SEPARADOR QUE LAS LLAMA DEPENDIENDO HACIENDOLO MODULAR
*/

int ft_print_char(va_list *args);
int ft_print_str(va_list *args);
int ft_print_di(va_list *args);
int ft_print_u(va_list *args);
int ft_print_hex(va_list *args, int uppercase);
int ft_print_ptr(va_list *args);

#endif
