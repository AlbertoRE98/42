/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:23:36 by aramos-e          #+#    #+#             */
/*   Updated: 2026/05/05 10:23:48 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeo.h"

int	main(void)
{
	printf("╔══════════════════════════════════════╗\n");
	printf("║     PUSH_SWAP OPERATIONS TESTER      ║\n");
	printf("╚══════════════════════════════════════╝\n");

	test_sa();
	test_sb();
	test_ss();
	test_pb();
	test_pa();
	test_ra();
	test_rb();
	test_rr();
	test_rra();
	test_rrb();
	test_rrr();
	test_combo();

	print_results();
	return (0);
}