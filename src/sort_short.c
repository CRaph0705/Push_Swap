/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:23:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/05 19:41:19 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_short(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);

void	sort_short(t_stack **stack_a, t_stack **stack_b)
{
	long	size;

	if (!stack_a || !(*stack_a) || is_sorted(stack_a))
		return ;
	size = ft_stacksize(*stack_a);
	if (size > 5)
		return ;
	if (size == 5)
		return (sort_five(stack_a, stack_b));
	if (size == 4)
		return (sort_four(stack_a, stack_b));
	if (size == 3)
		return (sort_three(stack_a));
	return (sa(stack_a, 1));
}

void	sort_three(t_stack **stack_a)
{
	long	min;
	long	max;

	min = get_stack_min_target(stack_a);
	max = get_stack_max_target(stack_a);
	if (is_asc_sorted(stack_a))
		return ;
	if ((*stack_a)->target_pos == min)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
		return ;
	}
	if ((*stack_a)->target_pos == max)
		ra(stack_a, 1);
	if ((*stack_a)->next->target_pos == max)
		rra(stack_a, 1);
	if (!is_asc_sorted(stack_a))
		sa(stack_a, 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;

	if (is_sorted(stack_a))
		return ;
	max = get_stack_max_target_node(stack_a);
	bring_node_on_top(stack_a, max, 'a', 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
	ra(stack_a, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*med;
	t_stack	*next_node;

	if (is_sorted(stack_a))
		return ;
	med = get_node_by_target_pos(stack_a, 2);
	next_node = get_next_node(stack_a, med);
	bring_node_on_top(stack_a, next_node, 'a', 1);
	pb(stack_a, stack_b, 1);
	next_node = get_next_node(stack_a, med);
	bring_node_on_top(stack_a, next_node, 'a', 1);
	pb(stack_a, stack_b, 1);
	if (is_asc_sorted(stack_a) == 0)
		sort_three(stack_a);
	pa(stack_b, stack_a, 1);
	pa(stack_b, stack_a, 1);
	if (!is_sorted(stack_a))
		sa(stack_a, 1);
}
