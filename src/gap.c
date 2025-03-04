/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:09 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/04 14:50:19 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_gap_bot(t_stack *node, t_stack **stack);

long	get_gap_bot(t_stack *node, t_stack **stack)
{
	long	gap;

	gap = -1;
	if (!(!node || !stack || !(*stack)))
		gap = (ft_stacksize((*stack)) - 1) - node->index;
	return (gap);
}
