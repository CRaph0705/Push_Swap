/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rapid_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:47:11 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/26 14:34:00 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
https://fr.wikipedia.org/wiki/Tri_rapide
https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif
*/

/* void	rapid_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pivot_a;
	t_stack	*pivot_b;
	// long	chunk_size;

	// chunk_size = ft_stacksize(*stack_a);
	pivot_a = NULL;
	pivot_b = NULL;

	pivot_a = get_median_target_pos(stack_a, ft_stacksize(*stack_a));
	pivot_b = get_median_target_pos(stack_b, 0);
	while ((*stack_a) != pivot_a)
	{
		if ((*stack_a)->target_pos > pivot_a->target_pos)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	ft_putstr("stack a\n");
	display_stack(stack_a, 1);
	ft_putstr("stack b\n");
	display_stack(stack_b, 1);
} */
