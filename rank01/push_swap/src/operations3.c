/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:53:02 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/04 13:18:27 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s)
{
	if (!s->a || !s->a->next)
		return ;
	reverse_rotate(&s->a);
	print_operation("rra");
}

void	rrb(t_stack *s)
{
	if (!s->b || !s->b->next)
		return ;
	reverse_rotate(&s->b);
	print_operation("rrb");
}

void	rrr(t_stack *s)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = 0;
	rotated_b = 0;
	if (s->a && s->a->next)
	{
		reverse_rotate(&s->a);
		rotated_a = 1;
	}
	if (s->b && s->b->next)
	{
		reverse_rotate(&s->b);
		rotated_b = 1;
	}
	if (rotated_a || rotated_b)
		print_operation("rrr");
}

