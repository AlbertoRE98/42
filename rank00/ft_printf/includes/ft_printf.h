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
# define FT_PRINTF_H

# include <unistd.h>
# include <varargs.h>
# include <stdlib.h>

/*
FUNCION PRINCIPAL NECESARIA
*/
int	ft_printf(char const *,...);

/*
FUNCIONES DE UTILIDAD PARA ESCRITURA
*/
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned long long nbr, char *base);

/*
ESQUELETO Y FUNCIONES A LLAMAR PARA CONVERTIR Y PARSEAR
*/



#endif
