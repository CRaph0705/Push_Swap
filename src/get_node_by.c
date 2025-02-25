/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_by.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:06:43 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/25 12:02:23 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*get_node_by_target_pos(t_stack **stack, long target_pos);
t_stack			*get_node_by_index(t_stack **stack, long index);
t_stack			*get_node_by_value(t_stack **stack, int value);

t_stack	*get_node_by_target_pos(t_stack **stack, long target)
{
	t_stack	*cursor;

	cursor = NULL;
	if (stack && (*stack) && target >= 0)
	{
		cursor = (*stack);
		while (cursor != NULL && cursor->target_pos != target)
			cursor = cursor->next;
	}
	return (cursor);
}

t_stack	*get_node_by_index(t_stack **stack, long target)
{
	t_stack	*cursor;

	cursor = NULL;
	if (!(!stack || !(*stack) || !target))
	{
		cursor = (*stack);
		while (cursor->index != target)
			cursor = cursor->next;
	}
	return (cursor);
}

t_stack	*get_node_by_value(t_stack **stack, int target)
{
	t_stack	*cursor;

	cursor = NULL;
	if (!(!stack || !(*stack) || !target))
	{
		cursor = (*stack);
		while (cursor->value != target)
			cursor = cursor->next;
	}
	return (cursor);
}
