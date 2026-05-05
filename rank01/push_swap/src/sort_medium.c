/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:53:59 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/05 10:15:07 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	long	low;
	long	high;
	long	mid;
	long	sqr;

	if (n < 0)
		return (0);
	if (n <= 1)
		return (n);
	low = 0;
	high = n;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		sqr = mid * mid;
		if (sqr == n)
			return ((int)mid);
		if (sqr < n)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return ((int)high);
}
