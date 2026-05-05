/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:22:23 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/05 10:23:07 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeo.h"

static int	tests_passed = 0;
static int	tests_failed = 0;

static void	check(const char *name, int condition)
{
	if (condition)
	{
		printf("  ✅ %s\n", name);
		tests_passed++;
	}
	else
	{
		printf("  ❌ %s\n", name);
		tests_failed++;
	}
}

static void	suite_header(const char *name)
{
	printf("\n📦 %s\n", name);
}

void	test_sa(void)
{
	t_stack	*s;
	int		input[] = {1, 2, 3};
	int		exp[] = {2, 1, 3};

	suite_header("op_sa");
	s = init_test_stack(input, 3);
	op_sa(s);
	check("swaps first two", stack_equals(s->a, exp, 3));
	// Single element
	free_test_stack(s);
	s = init_test_stack((int[]){42}, 1);
	op_sa(s);
	check("single element unchanged", stack_equals(s->a, (int[]){42}, 1));
	// Empty
	free_test_stack(s);
	s = init_test_stack(NULL, 0);
	op_sa(s);
	check("empty stack safe", s->a == NULL);

	free_test_stack(s);
}

void	test_sb(void)
{
	t_stack	*s;
	int		input[] = {5, 6, 7};
	int		exp[] = {6, 5, 7};

	suite_header("op_sb");
	s = init_test_stack(input, 3);

	op_pb(s);
	op_pb(s);
	op_pb(s);

	op_sb(s);
	check("swaps B first two", stack_equals(s->b, exp, 3));

	free_test_stack(s);
}

void	test_ss(void)
{
	t_stack	*s;
	int		a_in[] = {1, 2};
	int		b_in[] = {5, 6};

	suite_header("op_ss");
	s = init_test_stack(a_in, 2);
	stack_push(&s->b, 6);
	stack_push(&s->b, 5);
	s->size_b = 2;
	
	op_ss(s);
	check("swaps both stacks", 
		stack_equals(s->a, (int[]){2, 1}, 2) &&
		stack_equals(s->b, (int[]){6, 5}, 2));
	
	free_test_stack(s);
}

void	test_pb(void)
{
	t_stack	*s;

	suite_header("op_pb");
	s = init_test_stack((int[]){1, 2, 3}, 3);
	
	op_pb(s);
	check("pushes top A to B", 
		stack_equals(s->a, (int[]){2, 3}, 2) &&
		stack_equals(s->b, (int[]){1}, 1) &&
		s->size_a == 2 && s->size_b == 1);
	
	op_pb(s);
	check("pushes again",
		stack_equals(s->a, (int[]){3}, 1) &&
		stack_equals(s->b, (int[]){2, 1}, 2));
	
	// Empty A
	free_test_stack(s);
	s = init_test_stack(NULL, 0);
	op_pb(s);
	check("empty A safe", s->b == NULL);
	
	free_test_stack(s);
}

void	test_pa(void)
{
	t_stack	*s;

	suite_header("op_pa");
	s = init_test_stack((int[]){3}, 1);
	stack_push(&s->b, 1);
	stack_push(&s->b, 2);
	s->size_a = 1;
	s->size_b = 2;
	
	op_pa(s);
	check("pushes top B to A",
		stack_equals(s->a, (int[]){2, 3}, 2) &&
		stack_equals(s->b, (int[]){1}, 1));
	
	free_test_stack(s);
}

void	test_ra(void)
{
	t_stack	*s;
	int		input[] = {1, 2, 3};
	int		exp[] = {2, 3, 1};

	suite_header("ra");
	s = init_test_stack(input, 3);
	
	ra(s);
	check("rotates up", stack_equals(s->a, exp, 3));
	
	// Single element
	free_test_stack(s);
	s = init_test_stack((int[]){42}, 1);
	ra(s);
	check("single element unchanged", stack_equals(s->a, (int[]){42}, 1));
	
	free_test_stack(s);
}

void	test_rb(void)
{
	t_stack	*s;

	suite_header("rb");
	s = init_test_stack((int[]){1, 2, 3}, 3);
	op_pb(s);
	op_pb(s);
	op_pb(s);
	
	rb(s);
	check("rotates B up", stack_equals(s->b, (int[]){2, 3, 1}, 3));
	
	free_test_stack(s);
}

void	test_rr(void)
{
	t_stack	*s;

	suite_header("rr");
	s = init_test_stack((int[]){1, 2, 3}, 3);
	stack_push(&s->b, 6);
	stack_push(&s->b, 4);
	stack_push(&s->b, 5);
	s->size_b = 3;
	
	rr(s);
	check("rotates both",
		stack_equals(s->a, (int[]){2, 3, 1}, 2) &&
		stack_equals(s->b, (int[]){4, 5, 6}, 3));
	
	free_test_stack(s);
}

void	test_rra(void)
{
	t_stack	*s;
	int		input[] = {1, 2, 3};
	int		exp[] = {3, 1, 2};

	suite_header("rra");
	s = init_test_stack(input, 3);
	
	rra(s);
	check("reverse rotates", stack_equals(s->a, exp, 3));
	
	free_test_stack(s);
}

void	test_rrb(void)
{
	t_stack	*s;

	suite_header("rrb");
	s = init_test_stack((int[]){1, 2, 3}, 3);
	op_pb(s);
	op_pb(s);
	op_pb(s);
	
	rrb(s);
	check("reverse rotates B", stack_equals(s->b, (int[]){3, 1, 2}, 3));
	
	free_test_stack(s);
}

void	test_rrr(void)
{
	t_stack	*s;

	suite_header("rrr");
	s = init_test_stack((int[]){1, 2, 3}, 3);
	stack_push(&s->b, 6);
	stack_push(&s->b, 4);
	stack_push(&s->b, 5);
	s->size_b = 3;
	
	rrr(s);
	check("reverse rotates both",
		stack_equals(s->a, (int[]){3, 1, 2}, 3) &&
		stack_equals(s->b, (int[]){6, 4, 5}, 3));
	
	free_test_stack(s);
}

void	test_combo(void)
{
	t_stack	*s;

	suite_header("combo test: pb pb sa pa pa");
	s = init_test_stack((int[]){1, 2, 3}, 3);
	
	op_pb(s);  // A=[2,3], B=[1]
	op_pb(s);  // A=[3], B=[2,1]
	op_sa(s);  // A=[3], B=[1,2] — wait, sa is on A!
	
	// Actually sa swaps A, but A has only [3], so no change
	// Let me redo: pb pb sb pa pa
	
	free_test_stack(s);
	s = init_test_stack((int[]){1, 2, 3}, 3);
	
	op_pb(s);   // A=[2,3], B=[1]
	op_pb(s);   // A=[3], B=[2,1]
	op_sb(s);   // A=[3], B=[1,2]
	op_pa(s);   // A=[1,3], B=[2]
	op_pa(s);   // A=[2,1,3], B=[]
	
	// Hmm not sorted. Let's try a known sequence:
	// Sort [3,1,2]: ra pb pb sa pa pa
	
	free_test_stack(s);
	s = init_test_stack((int[]){3, 1, 2}, 3);
	
	ra(s);      // A=[1,2,3]
	op_pb(s);   // A=[2,3], B=[1]
	op_pb(s);   // A=[3], B=[2,1]
	op_sa(s);   // A=[3], B=[1,2] — sb! not sa
	// Correction:
	
	free_test_stack(s);
	s = init_test_stack((int[]){3, 1, 2}, 3);
	
	ra(s);      // A=[1,2,3]
	op_pb(s);   // A=[2,3], B=[1]
	op_pb(s);   // A=[3], B=[2,1]
	op_sb(s);   // A=[3], B=[1,2]
	op_pa(s);   // A=[1,3], B=[2]
	op_pa(s);   // A=[2,1,3] — still not right
	
	// Actually to sort [3,1,2]: pb ra pa sa
	// Let's trace: [3,1,2]
	free_test_stack(s);
	s = init_test_stack((int[]){3, 1, 2}, 3);
	
	op_pb(s);   // A=[1,2], B=[3]
	ra(s);      // A=[2,1], B=[3]
	op_pa(s);   // A=[3,2,1], B=[] — no
	
	// Known solution for [3,1,2]: sa ra (from subject example)
	free_test_stack(s);
	s = init_test_stack((int[]){3, 1, 2}, 3);
	
	op_sa(s);   // A=[1,3,2]
	ra(s);      // A=[3,2,1] — no, that's [3,2,1]
	// sa: swap first two: [1,3,2]
	// ra: rotate: [3,2,1]
	
	// Actually [3,1,2] sorted is [1,2,3]
	// sa gives [1,3,2], then rra gives [2,1,3], then sa gives [1,2,3]
	
	free_test_stack(s);
	s = init_test_stack((int[]){3, 1, 2}, 3);
	
	op_sa(s);   // [1,3,2]
	rra(s);     // [2,1,3]
	op_sa(s);   // [1,2,3]
	
	check("sort [3,1,2] with sa rra sa", stack_equals(s->a, (int[]){1, 2, 3}, 3));
	
	free_test_stack(s);
}

void	print_results(void)
{
	printf("\n═══════════════════════════════\n");
	printf("  TESTS PASSED: %d\n", tests_passed);
	printf("  TESTS FAILED: %d\n", tests_failed);
	printf("═══════════════════════════════\n");
	if (tests_failed == 0)
		printf("🎉 ALL TESTS PASSED!\n");
	else
		printf("⚠️  SOME TESTS FAILED\n");
}