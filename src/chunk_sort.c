/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:23:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/26 16:17:53 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pivot_a;
	t_stack	*pivot_b;
	// long	chunk_size;

	// chunk_size = ft_stacksize(*stack_a);
	pivot_a = NULL;
	pivot_b = NULL;

	pivot_a = get_target_pos_median(stack_a, ft_stacksize(*stack_a));
	ft_printf("pivot_a->target_pos = %i\n", pivot_a->target_pos);
	pivot_b = get_target_pos_median(stack_b, ft_stacksize(*stack_b));
	ft_printf("1er while\n");
	epure_a_over_median(stack_a, stack_b, pivot_a);
	/* <DEBUG> */
	ft_putstr("\nstack a\n");
	display_stack(stack_a, 1);
	ft_putstr("stack b\n");
	display_stack(stack_b, 1);
	ft_printf("\n2e while\n");
	/* </DEBUG> */
	pivot_a = get_target_pos_median(stack_a, ft_stacksize(*stack_a));
	pivot_b = get_target_pos_median(stack_b, ft_stacksize(*stack_b));
	ft_printf("pivot_a->target_pos = %i\n", pivot_a->target_pos);
	ft_printf("pivot_b->target_pos = %i\n", pivot_b->target_pos);

	epure_a_over_median(stack_a, stack_b, pivot_a);

	ft_putstr("stack a\n");
	display_stack(stack_a, 1);
	ft_putstr("stack b\n");
	display_stack(stack_b, 1);
}

// mediane ou point pivot
// chunk 1 -> target pos entre 0 et index max / 4
// chunk 2 -> target pos entre index max / 4 et index max / 2
// chunk 3 -> target pos entre index max / 2 et 3 index max / 4
// chunk 4 -> target pos entre 3 index max / 4 et index max
