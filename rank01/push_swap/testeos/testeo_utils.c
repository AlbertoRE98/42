/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeo_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:17:29 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/05 10:20:40 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeo.h"

void	print_stack(t_node *stack, const char *name)
{
	printf("%s [top→]: ", name);
	if (!stack)
	{
		printf("(empty)\n");
		return ;
	}
	while (stack)
	{
		printf("%d", stack->value);
		if (stack->next)
			printf(" → ");
		stack = stack->next;
	}
	printf("\n");
}

void	print_both(t_stack *s)
{
	print_stack(s->a, "A");
	print_stack(s->b, "B");
	printf("size_a: %d | size_b: %d\n", s->size_a, s->size_b);
	printf("------------------------\n");
}

t_stack	*init_test_stack(int *values, int count)
{
	t_stack	*s;
	int		i;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->a = NULL;
	s->b = NULL;
	s->size_a = 0;
	s->size_b = 0;
	i = count - 1;
	while (i >= 0)
	{
		stack_push(&s->a, values[i]);
		s->size_a++;
		i--;
	}
	return (s);
}

void	free_test_stack(t_stack *s)
{
	if (!s)
		return ;
	free_stack(&s->a);
	free_stack(&s->b);
	free(s);
}

int	stack_equals(t_node *stack, int *expected, int count)
{
	int	i;

	i = 0;
	while (stack && i < count)
	{
		if (stack->value != expected[i])
			return (0);
		stack = stack->next;
		i++;
	}
	return (stack == NULL && i == count);
}
