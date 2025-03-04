/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:32:45 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 18:40:36 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack);
int	is_asc_sorted(t_stack **stack);
int	is_desc_sorted(t_stack **stack);

/* compare index and target_pos foreach node of specified stack */
int	is_sorted(t_stack **stack)
{
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (0);
	cursor = *stack;
	while (cursor != NULL)
	{
		if (cursor->index != cursor->target_pos)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	is_asc_sorted(t_stack **stack)
{
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (0);
	cursor = *stack;
	while (cursor->next != NULL)
	{
		if (cursor->target_pos > cursor->next->target_pos)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int	is_desc_sorted(t_stack **stack)
{
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (0);
	cursor = *stack;
	while (cursor->next != NULL)
	{
		if (cursor->target_pos < cursor->next->target_pos)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
