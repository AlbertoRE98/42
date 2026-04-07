/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:58:35 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 12:59:15 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbr_digits(int nbr)
{
	int	number_d;

	number_d = 0;
	while (nbr != 0)
	{
		number_d++;
		nbr = nbr / 10;
	}
	return (number_d);
}

static	int	ten_power(int nb)
{
	int	pwd;

	pwd = 1;
	while (nb / 10 != 0)
	{
		pwd *= 10;
		nb /= 10;
	}
	return (pwd);
}

static char	*itoahelper(char *res, long int nb)
{
	int	index;
	int	power;

	index = 0;
	power = ten_power(nb);
	if (nb < 0)
	{
		res[index] = '-';
		index++;
		nb *= -1;
	}
	while (power > 0)
	{
		res[index] = nb / power + '0';
		nb %= power;
		power /= 10;
		index++;
	}
	res[index] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			number_digits;
	long int	nb;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	number_digits = nbr_digits(n);
	if (n < 0)
		number_digits++;
	res = malloc(sizeof(char) * (number_digits + 1));
	if (!res)
		return (NULL);
	nb = n;
	res = itoahelper(res, nb);
	return (res);
}
