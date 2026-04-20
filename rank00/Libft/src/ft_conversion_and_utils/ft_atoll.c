/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:50:58 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/07 12:53:10 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *ptr)
{
	const char		*tmp;
	int				sign;
	long long int	res;

	res = 0;
	sign = 1;
	tmp = ptr;
	if (!tmp)
		return (0);
	while (ft_isspace(*tmp) && tmp)
		tmp++;
	if (*tmp == '-' || *tmp == '+')
	{
		if (*tmp == '-')
			sign *= -1;
		tmp++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		res = (res * 10) + (*tmp - '0');
		tmp++;
	}
	return (res * sign);
}
