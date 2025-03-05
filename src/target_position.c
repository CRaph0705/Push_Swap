/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:59:14 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/05 19:54:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_pos(t_stack *node, long pos);
long	get_target_pos(t_stack *node);
void	init_target_pos(t_stack **stack, int *array, size_t len);
t_stack	*get_stack_max_target_node(t_stack **stack);
void	ft_sort_int_tab(int *tab, size_t size);
long	get_num_index(int n, int *array, size_t size);

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

/* return node with max target_pos in stack */
t_stack	*get_stack_max_target_node(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*max_target;

	if (!stack || !(*stack))
		return (NULL);
	cursor = (*stack);
	max_target = cursor;
	while (cursor != NULL)
	{
		if (cursor->target_pos > max_target->target_pos)
		{
			max_target = cursor;
		}
		cursor = cursor->next;
	}
	return (max_target);
}

//sort array, when int array[i] == node->value : node->target_pos = i;
void	ft_sort_int_tab(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
