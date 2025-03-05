/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smarter_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:16:22 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/05 11:58:25 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smarter_sort(t_stack **stack_a, t_stack **stack_b);

void	smarter_sort(t_stack **stack_a, t_stack **stack_b)
{
	long	min_target;
	t_stack	*target_node;

	while ((*stack_a) != NULL)
	{
		min_target = get_stack_min_target(stack_a);
		target_node = get_node_by_target_pos(stack_a, min_target);
		if (target_node == NULL || min_target == -1)
		{
			return ;
		}
		while ((*stack_a) != target_node)
		{
			if (target_node->index <= (ft_stacksize(*stack_a) / 2))
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
	}
	while ((*stack_b) != NULL)
		pa(stack_b, stack_a, 1);
	return ;
}
// si trop proche de med par rapport à top ou bot skip ??