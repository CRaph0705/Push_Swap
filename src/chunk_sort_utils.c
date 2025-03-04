/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:35:49 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/04 21:21:48 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_chunk_max_target(t_stack **stack, long chunk_size);
t_stack	*get_next_node(t_stack **stack, t_stack *limit);
t_stack	*get_chunk_median(t_stack **stack, t_stack *chunk_limit);
t_stack	*get_chunk_min_node(t_stack **stack, t_stack *chunk_limit);
void	bring_two_nodes_and_reorder(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_a, t_stack *node_b);

/* returns max target_position of **stack */
long	get_chunk_max_target(t_stack **stack, long chunk_size)
{
	t_stack	*cursor;
	long	max_target;
	long	i;

	if (!stack || !(*stack) || !chunk_size)
		return (-1);
	cursor = (*stack);
	i = 0;
	max_target = cursor->target_pos;
	while (i < chunk_size && cursor != NULL)
	{
		if (cursor->target_pos > max_target)
		{
			max_target = cursor->target_pos;
		}
		cursor = cursor->next;
		i++;
	}
	return (max_target);
}

/* return first next node below limit or limit if none found */
t_stack	*get_next_node(t_stack **stack, t_stack *limit)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*cursor;

	if (!stack || !(*stack) || !limit)
		return (NULL);
	cursor = (*stack);
	first_node = NULL;
	last_node = NULL;
	while (cursor != NULL)
	{
		if (cursor->target_pos < limit->target_pos)
		{
			if (first_node == NULL)
				first_node = cursor;
			last_node = cursor;
		}
		cursor = cursor->next;
	}
	if (first_node == NULL)
		return (limit);
	if (ft_stacksize(*stack) - last_node->index < first_node->index)
		return (last_node);
	return (first_node);
}

void	bring_two_nodes_and_reorder(t_stack **stack_a, t_stack **stack_b,
	t_stack *node_a, t_stack *node_b)
{
	bring_node_on_top(stack_b, node_a, 'b');
	pa(stack_b, stack_a, 1);
	if (node_b->index <= (ft_stacksize(*stack_b) / 2))
		rr(stack_a, stack_b, 1);
	else
		ra(stack_a, 1);
	bring_node_on_top(stack_b, node_b, 'b');
	pa(stack_b, stack_a, 1);
	rra(stack_a, 1);
}

/* return median node in current chunk */
t_stack	*get_chunk_median(t_stack **stack, t_stack *chunk_limit)
{
	t_stack	*median;
	long	max_pos;
	long	min_pos;

	if (!stack || !(*stack))
		return (NULL);
	if (chunk_limit == NULL)
		chunk_limit = ft_stacklast(stack);
	min_pos = get_chunk_min_node(stack, chunk_limit)->target_pos;
	max_pos = chunk_limit->target_pos;
	median = NULL;
	median = get_node_by_target_pos(stack, (min_pos + max_pos) / 2);
	return (median);
}

/* return node with min target_pos in current chunk */
t_stack	*get_chunk_min_node(t_stack **stack, t_stack *chunk_limit)
{
	t_stack	*cursor;
	t_stack	*chunk_min;

	if (!stack || !(*stack))
		return (NULL);
	if (!chunk_limit)
		chunk_limit = ft_stacklast(stack);
	cursor = (*stack);
	chunk_min = cursor;
	while (cursor != NULL)
	{
		if (cursor->target_pos < chunk_min->target_pos)
		{
			chunk_min = cursor;
		}
		cursor = cursor->next;
	}
	return (chunk_min);
}
