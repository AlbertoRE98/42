/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:19:12 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/05 10:19:47 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTEO_H
# define TESTEO_H

# include "../include/push_swap.h"
# include <stdio.h>


void	print_stack(t_node *stack, const char *name);
void	print_both(t_stack *s);
t_stack	*init_test_stack(int *values, int count);
void	free_test_stack(t_stack *s);
int		stack_equals(t_node *stack, int *expected, int count);


void	test_sa(void);
void	test_sb(void);
void	test_ss(void);
void	test_pa(void);
void	test_pb(void);
void	test_ra(void);
void	test_rb(void);
void	test_rr(void);
void	test_rra(void);
void	test_rrb(void);
void	test_rrr(void);
void	test_combo(void);

#endif