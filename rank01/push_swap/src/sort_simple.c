/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:16:27 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/05 11:38:38 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_value_pos(t_node *stack)
{
	t_node	*current_node;
	int		min_pos;
	int		min_value;
	int		pos;

	if (!stack)
		return (-1);
	current_node = stack;
	min_pos = -1;
	pos = 0;
	min_value = current_node->value;
	while (current_node)
	{
		if (current_node->value < min_value)
		{
			min_value = current_node->value;
			min_pos = pos;
		}
		pos++;
		current_node = current_node->next;
	}
	return (min_pos);
}

static	void	rotate_helper_to_top(t_stack *s, int minimum_pos)
{
	int	i;
	int	size;

	size = s->size_a;
	if (minimum_pos <= (size / 2))
	{
		i = 0;
		while (i < minimum_pos)
		{
			ra(s->a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - minimum_pos)
		{
			rra(s->a);
			i++;
		}
	}
}

void	sort_simple(t_stack *s)
{
	int	counter;
	int	min_pos;

	if (!s)
	{
		write(1, "No hay stack creado", 20);
		return ;
	}
	counter = s->size_a;
	while (counter > 0)
	{
		min_pos = min_value_pos(s->a);
		rotate_helper_to_top(s, min_pos);
		op_pb(s);
		counter--;
	}
	counter = s->size_b;
	while (counter > 0)
	{
		op_pa(s);
		counter--;
	}
}

