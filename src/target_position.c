/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:59:14 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/19 15:53:06 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_target_pos(t_stack **stack_a);
void	set_target_pos(t_stack *node, long pos);

int	get_target_pos(t_stack *node)
{
	return (0);
}

void	fill_target_pos(t_stack **stack)
{
	t_stack	*current;
	long	pos;

	if (!stack || !(*stack))
		return ;
	pos = -1;
	current = (*stack);
	while ((*stack) != NULL)
	{
		set_target_pos(current, pos);
		current = current->next;
	}
}

void	set_target_pos(t_stack *node, long pos)
{
	if (!node || !pos)
		return ;
	node->target_pos = pos;
}
