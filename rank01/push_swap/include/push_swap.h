/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:40:51 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/04 15:06:58 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef enum e_disorder_level
{
	DISORDER_LOW,
	DISORDER_MEDIUM,
	DISORDER_HIGH
}	t_disorder_level;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*a;
	t_node		*b;

	int			size_a;
	int			size_b;

}	t_stack;

t_node		*new_node(int value);
void		stack_push(t_node **stack, int value);
int			stack_pop(t_node **stack);
int			stack_size(t_node *stack);
int			stack_peek(t_node *stack);
void		free_stack(t_node **stack);
void		reverse_rotate(t_node **stack);
void		rotate(t_node **stack);

void		op_ss(t_stack *s);
void		op_sb(t_stack *s);
void		op_sa(t_stack *s);
void		rb(t_stack *s);
void		ra(t_stack *s);
void		rr(t_stack *s);
void		op_pa(t_stack *s);
void		op_pb(t_stack *s);
void		rra(t_stack *s);
void		rrb(t_stack *s);
void		rrr(t_stack *s);
void		print_operation(const char *op);

double		compute_disorder_index(t_node *stack);
void		sort_adaptative(t_node *stack);

void		sort_simple(t_node **stack);
void		sort_medium(t_node **stack);
void		sort_complex(t_node **stack);


#endif
