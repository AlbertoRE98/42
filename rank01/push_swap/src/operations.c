/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:42:42 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/04 13:21:59 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(const char *op)
{
	int	i;

	i = 0;
	while (op[i])
		i++;
	write(1, op, i);
	write(1, "\n", 1);
}

static void	swap_values(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	op_sa(t_stack *s)
{	
	if (!s->a || !s->a->next)
		return ;
	swap_values(s->a);
	print_operation("sa");
}

void	op_sb(t_stack *s)
{	
	if (!s->b || !s->b->next)
		return ;
	swap_values(s->b);
	print_operation("sb");
}

void	op_ss(t_stack *s)
{
	swap_values(s->a);
	swap_values(s->b);
	if (s->a && s->a->next || s->b && s->b->next)
		print_operation("ss");
}
