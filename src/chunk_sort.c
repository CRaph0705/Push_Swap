/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:23:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/25 19:24:13 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	long	min_target;
	t_stack	*target_node;

	while ((*stack_a) != NULL)
	{
		min_target = get_stack_min_target(stack_a);
		target_node = get_node_by_target_pos(stack_a, min_target);
		if (target_node == NULL || min_target == -1)
		{
			ft_printf("insertion_sort, error");
			return ;
		}
		while ((*stack_a) != target_node)
		{
			if (target_node->index <= (ft_stacksize(*stack_a) / 2))
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	while ((*stack_b) != NULL)
		pa(stack_b, stack_a);
	return ;
}
