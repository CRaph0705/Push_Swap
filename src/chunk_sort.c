/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:23:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/28 19:02:55 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_chunk(t_stack **stack_a, t_stack *limit, t_stack **stack_b);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b);

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	sort_in_chunks(stack_a, stack_b);
	pushback_chunks(stack_a, stack_b);
}

void	sort_in_chunks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limit;
	long	max_target;
	long	n;

	if (!stack_a || !(*stack_a))
		return ;
	max_target = ft_stacksize(*stack_a) - 1;
	n = 1;
	while (*stack_a != NULL && n < 5)
	{
		limit = get_node_by_target_pos(stack_a, (max_target / 4) * n);
		fill_chunk(stack_a, limit, stack_b);
		n++;
	}
	while (*stack_a != NULL)
		pb(stack_a, stack_b);
}

void	bring_node_on_top_of_a(t_stack **stack_a, t_stack *node)
{
	while (*stack_a != node)
	{
		if (node->index <= (ft_stacksize(*stack_a) / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	fill_chunk(t_stack **stack_a, t_stack *limit, t_stack **stack_b)
{
	t_stack	*next_node;
	t_stack	*median;

	median = get_chunk_median(stack_a, limit);
	next_node = get_next_node(stack_a, limit);
	while (next_node != limit)
	{
		bring_node_on_top_of_a(stack_a, next_node);
		pb(stack_a, stack_b);
		if ((*stack_b)->target_pos < median->target_pos)
			rb(stack_b);
		next_node = get_next_node(stack_a, limit);
	}
}
