/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:04:53 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 14:06:22 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long			get_stack_min_target(t_stack **stack);

long	get_stack_min_target(t_stack **stack)
{
	t_stack	*cursor;
	long	min_target;

	if (!stack || !(*stack))
		return (-1);
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

long	get_stack_max_target(t_stack **stack)
{
	t_stack	*cursor;
	long	max_target;

	if (!stack || !(*stack))
		return (-1);
	cursor = (*stack);
	max_target = cursor->target_pos;
	while (cursor != NULL)
	{
		if (cursor->target_pos > max_target)
		{
			max_target = cursor->target_pos;
		}
		cursor = cursor->next;
	}
	return (max_target);
}
