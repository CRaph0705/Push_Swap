/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:09 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/25 12:23:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_gap_mid(t_stack *node, t_stack **stack);
long	get_gap_bot(t_stack *node, t_stack **stack);
// long	ft_stacksize(t_stack *stack); 
//>> compare gap with node until end of stack ?
// index max - index > index max / 2 ??

long	get_gap_mid(t_stack *node, t_stack **stack)
{
	long	gap;

	gap = 0;
	return (gap);
}

// si index max - pos < index / 2 == 0 < pos < med
// index - pos < index - med (== index / 2)
// index - pos / 2 < index

long	get_gap_bot(t_stack *node, t_stack **stack)
{
	long	gap;

	gap = -1;
	if (!(!node || !stack || !(*stack)))
		gap = (ft_stacksize((*stack)) - 1) - node->index;
	return (gap);
}
