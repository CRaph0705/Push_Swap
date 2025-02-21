/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:04:53 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/21 17:14:59 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long			get_stack_min_target(t_stack **stack);

// dans current stack, return le node dont target_pos == min

long	get_stack_min_target(t_stack **stack)
{
	t_stack	*cursor;
	long	min_target;

	if (!stack || !(*stack))
		return (ft_printf("!stack || !(*stack)"), -1);
	cursor = (*stack);
	min_target = cursor->target_pos;
	while (cursor != NULL)
	{
		if (cursor->target_pos < min_target)
		{
			min_target = cursor->target_pos;
		}
		cursor = cursor->next;
	}
	return (min_target);
}
