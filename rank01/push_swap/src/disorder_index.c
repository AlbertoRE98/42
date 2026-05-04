/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:30:37 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/04 15:07:21 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder_index(t_node *stack)
{
	double	mistakes;
	double	total_pairs;
	t_node	*outer;
	t_node	*inner;

	if (stack_size(stack) <= 1)
		return (0.0);
	total_pairs = 0;
	mistakes = 0;
	while (outer && outer->next)
	{
		inner = outer->next;
		while (inner && inner ->next)
		{
			total_pairs++;
			if (outer->value > inner->value)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (mistakes / total_pairs);
}

static	t_disorder_level	get_disorder_level(double disorder_level)
{
	if (disorder_level < 0.2)
		return (DISORDER_LOW);
	else if (disorder_level < 0.5)
		return (DISORDER_MEDIUM);
	else
		return (DISORDER_HIGH);
}

void	sort_adaptative(t_node *stack)
{
	float				disorder_level;
	t_disorder_level	disorder;

	disorder_level = compute_disorder_index(stack);
	disorder = get_disorder_level(disorder_level);
	if (disorder == DISORDER_LOW)
		sort_simple(&stack);
	else if (disorder == DISORDER_MEDIUM)
		sort_medium(&stack);
	else
		sort_complex(&stack);
}
