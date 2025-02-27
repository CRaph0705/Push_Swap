/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:35:49 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/27 13:22:41 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
long	get_chunk_min_target(t_stack **stack, long chunk_size);
long	get_chunk_max_target(t_stack **stack, long chunk_size);
t_stack	*get_target_pos_median(t_stack **stack, long chunk_size);

t_stack	*get_target_pos_median(t_stack **stack, long chunk_size)
{
	t_stack	*median;
	long	max_target_pos;
	long	min_target_pos;
	long	median_pos;
	median = NULL;
	if (stack && (*stack) && chunk_size)
	{
		max_target_pos = get_chunk_max_target(stack, chunk_size);
		min_target_pos = get_chunk_min_target(stack, chunk_size);
		median_pos = (min_target_pos + max_target_pos) / 2;
		median = (*stack);
		while (median->target_pos != median_pos)
			median = median->next;
	}
	return (median);
}

long	get_chunk_min_target(t_stack **stack, long chunk_size)
{
	t_stack	*cursor;
	long	min_target;
	long	i;

	if (!stack || !(*stack) || !chunk_size)
		return (ft_printf("!stack || !(*stack) || !chunk_size"), -1);
	cursor = (*stack);
	i = 0;
	min_target = cursor->target_pos;
	while (i < chunk_size && cursor != NULL)
	{
		if (cursor->target_pos < min_target)
		{
			min_target = cursor->target_pos;
		}
		cursor = cursor->next;
		i++;
	}
	return (min_target);
}
/* returns max target_position of **stack */
long	get_chunk_max_target(t_stack **stack, long chunk_size)
{
	t_stack	*cursor;
	long	max_target;
	long	i;

	if (!stack || !(*stack) || !chunk_size)
		return (ft_printf("!stack || !(*stack) || !chunk_size"), -1);
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

void	epure_a_over_median(t_stack **stack_a, t_stack **stack_b, t_stack *pivot_a)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while ((*stack_a) != pivot_a)
		{
			if ((*stack_a)->target_pos > pivot_a->target_pos)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->target_pos < (ft_stacklast(stack_b))->target_pos || (*stack_b)->target_pos < (get_target_pos_median(stack_b, ft_stacksize(*stack_b)))->target_pos )
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		ra(stack_a);
		i++;
	}
}

/*//TODO >>>>>>>>>> fill chunk functions <<<<<<<<<< */
// while stack a != NULL 
//get_next_chunk(stack, chunk_limit);
// -> while (*stack)->target_pos < chunk_limit->target_pos
//get_next_chunk_node


// take short values first

//fill chunk in dest stack (stack b) with node from src stack (stack a) until node *limit excluded
void	fill_chunk(t_stack **stack_a, t_stack **stack_b)
{
	// long	max;
	t_stack	*next_node;
	t_stack *limit;
	long	max_target;
	long	n;
	if (!stack_a || !(*stack_a))
		return ;
	//6 chunks -> n chunks, n--;
	// target_max / 6
	// max = get_chunk_max_target(stack_a, ft_stacksize(*stack_a));
	// rotate next closest node in target chunk
	max_target = ft_stacksize(*stack_a) - 1;
	while (*stack_a != NULL)
	{
		n = 8;
		limit = get_node_by_target_pos(stack_a, (max_target / n));
		next_node = get_next_node(stack_a, limit);
		while (next_node != NULL)
		{
			while (stack_a != next_node)
				{
					if (next_node->index <= (ft_stacksize(*stack_a) / 2))
						ra(stack_a);
					else
						rra(stack_a);
				}
			pb(stack_a, stack_b);
			next_node = get_next_node(stack_a, limit);
		}
		n--;
	}
}
/* return first next node that goes in chunk */
t_stack	*get_next_node(t_stack **stack, t_stack *limit)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*cursor;

	if (!stack || !(*stack) || !limit)
		return ;
	cursor = (*stack);
	first_node = NULL;
	last_node = NULL;
	while (cursor != NULL)
	{
		if(cursor->target_pos <= limit->target_pos)
		{
			if (first_node == NULL) 
				first_node = cursor;
			last_node = cursor;
		}
		cursor = cursor->next;
	}
	if (ft_stacksize(*stack) - last_node->index < first_node->index)
		return (last_node);
	return(first_node);
}
