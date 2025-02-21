/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:59:14 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/21 17:14:02 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_pos(t_stack *node, long pos);
long	get_target_pos(t_stack *node);
void	init_target_pos(t_stack **stack, int *array, size_t len);

long	get_num_index(int n, int *array, size_t size)
{
	long	i;
	long	len;

	if (!array || !size)
		return (-1);
	len = size;
	i = 0;
	while (i < len && array[i] != n)
		i++;
	if (array[i] != n)
		return (-1);
	return (i);
}

//l.50 -> gérer error
void	init_target_pos(t_stack **stack, int *array, size_t len)
{
	t_stack	*current;
	long	pos;

	if (!stack || !(*stack))
		return ;
	pos = -1;
	current = (*stack);
	ft_sort_int_tab(array, len);
	while ((*stack) != NULL)
	{
		pos = get_num_index(current->value, array, len);
		if (pos == -1)
			return ;
		set_target_pos(current, pos);
		if (current->next == NULL)
			return ;
		current = current->next;
	}
}

void	set_target_pos(t_stack *node, long pos)
{
	if (!node || pos < 0)
		return ;
	node->target_pos = pos;
}

long	get_target_pos(t_stack *node)
{
	if (!node)
		return (-1);
	return (node->target_pos);
}
