/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:46:13 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/04 16:21:35 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return the closest node from top between node a and node b */
t_stack	*get_closest_node(t_stack **stack, t_stack *node_a, t_stack *node_b)
{
	t_stack	*min;
	t_stack	*max;
	long	len;

	if (!stack || !(*stack) || !node_a || !node_b)
		return (NULL);
	len = ft_stacksize(*stack);
	if (node_a->index < node_b->index)
	{
		min = node_a;
		max = node_b;
	}
	else
	{
		max = node_a;
		min = node_b;
	}
	if (len - max->index > min->index)
		return (min);
	return (max);
}
