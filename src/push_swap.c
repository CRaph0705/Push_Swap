/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:06 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 14:46:30 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b);

/* 
Display the smallest list of instructions possible to sort (asc) the stack a.
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	sort_short(stack_a, stack_b);
	chunk_sort(stack_a, stack_b);
}
