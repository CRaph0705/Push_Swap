/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:18:16 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/05 22:58:18 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pushback_max(t_stack **stack_a, t_stack **stack_b);
void		smart_pushback(t_stack **stack_a, t_stack **stack_b);
static int	is_close(t_stack *node, t_stack **stack, long n);

/* reinsert stack b chunks in stack a by desc order */
void	pushback_chunks(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	pushback_max(stack_a, stack_b);
	smart_pushback(stack_a, stack_b);
	while (is_sorted(stack_a) != 1)
		rra(stack_a, 1);
}

void	pushback_max(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	t_stack	*scnd_max;

	max = get_stack_max_target_node(stack_b);
	scnd_max = get_node_by_target_pos(stack_b, max->target_pos - 1);
	if (max == get_closest_node(stack_b, max, scnd_max) || !scnd_max)
	{
		bring_node_on_top(stack_b, max, 'b', 1);
		pa(stack_b, stack_a, 1);
		bring_node_on_top(stack_b, scnd_max, 'b', 1);
		pa(stack_b, stack_a, 1);
	}
	else
		bring_two_nodes_and_reorder(stack_a, stack_b, scnd_max, max);
}

void	smart_pushback(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_a;
	t_stack	*max_b;
	t_stack	*last_a;

	max_a = get_stack_max_target_node(stack_a);
	while ((*stack_b))
	{
		last_a = ft_stacklast(stack_a);
		max_b = get_stack_max_target_node(stack_b);
		if (max_a != last_a && last_a->target_pos > max_b->target_pos)
			rra(stack_a, 1);
		else if (is_close(max_b, stack_b, 3))
		{
			bring_node_on_top(stack_b, max_b, 'b', 1);
			pa(stack_b, stack_a, 1);
		}
		else if (last_a == max_a || (*stack_b)->target_pos > last_a->target_pos)
		{
			pa(stack_b, stack_a, 1);
			ra(stack_a, 1);
		}
		else
			bring_node_on_top(stack_b, max_b, 'b', 0);
	}
}

/* return 1 if target node is below n steps */
static int	is_close(t_stack *node, t_stack **stack, long n)
{
	long	i;
	t_stack	*cursor;

	if (ft_stacksize(*stack) > n * 2)
	{
		i = 0;
		cursor = *stack;
		while (i++ < n)
		{
			if (cursor == node)
				return (1);
			cursor = cursor->next;
		}
		i = 0;
		cursor = get_node_by_index(stack, ft_stacksize(*stack) - n);
		while (i++ < n - 1)
		{
			if (cursor == node)
				return (1);
			cursor = cursor->next;
		}
		return (0);
	}
	return (1);
}
