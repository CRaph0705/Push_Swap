/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:55:37 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/19 12:41:46 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indices(t_stack **stack);

void	update_indices(t_stack **stack)
{
	int		index;
	t_stack	*current;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
	return ;
}
