/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:23:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 22:38:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_chunk(t_stack **stack_a, t_stack *limit, t_stack **stack_b);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b);

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	sort_in_chunks(stack_a, stack_b);
	pushback_chunks(stack_a, stack_b);
}

void	sort_in_chunks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limit;
	long	max_target;
	long	n;
	long	nb_div;

	if (!stack_a || !(*stack_a))
		return ;
	max_target = ft_stacksize(*stack_a) - 1;
	if (ft_stacksize(*stack_a) > 100)
		nb_div = 9;
	else
		nb_div = 5;
	n = 1;
	while (*stack_a != NULL && n <= nb_div)
	{
		limit = get_node_by_target_pos(stack_a, (max_target / nb_div) * n);
		fill_chunk(stack_a, limit, stack_b);
		n++;
	}
	while (*stack_a != NULL)
		pb(stack_a, stack_b, 1);
}

void	bring_node_on_top(t_stack **stack, t_stack *node, char c)
{
	while (*stack != node)
	{
		if (c == 'a')
		{
			if (node->index <= (ft_stacksize(*stack) / 2))
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else
		{
			if (node->index <= (ft_stacksize(*stack) / 2))
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
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
		bring_node_on_top(stack_a, next_node, 'a');
		pb(stack_a, stack_b, 1);
		if ((*stack_b)->target_pos < median->target_pos)
			rb(stack_b, 1);
		next_node = get_next_node(stack_a, limit);
	}
}
