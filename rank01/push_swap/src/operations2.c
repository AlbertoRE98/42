/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:57:47 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/04 13:28:48 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *s)
{
	int	value;

	if (!s->b)
		return ;
	value = stack_pop(&s->b);
	stack_push(&s->a, value);
	s->size_a++;
	s->size_b--;
	print_operation("pa");
}

void	op_pb(t_stack *s)
{
	int	value;

	if (!s->a)
		return ;
	value = stack_pop(&s->a);
	stack_push(&s->b, value);
	s->size_a--;
	s->size_b++;
	print_operation("pb");
}

void	ra(t_stack *s)
{
	if (!s->a || !s->a->next)
		return ;
	rotate(&s->a);
	print_operation("ra");
}

void	rb(t_stack *s)
{
	if (!s->b || !s->b->next)
		return ;
	rotate(&s->b);
	print_operation("rb");
}

void	rr(t_stack *s)
{
	rotate(&s->a);
	rotate(&s->b);
	print_operation("rr");
}
