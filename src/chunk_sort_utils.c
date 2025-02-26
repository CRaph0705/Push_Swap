/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:35:49 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/26 16:29:55 by rcochran         ###   ########.fr       */
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
