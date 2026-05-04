/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:46:35 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/04 13:12:06 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	stack_push(t_node **stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

int	stack_pop(t_node **stack)
{
	t_node	*tmp;
	int		value;

	if (!*stack)
		return (0);
	tmp = *stack;
	value = tmp->value;
	*stack = tmp->next;
	free (tmp);
	return (value);
}

int	stack_peek(t_node *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}

int	stack_size(t_node *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
