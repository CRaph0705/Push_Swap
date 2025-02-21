/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:32:26 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/21 17:18:44 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			exec_ra(t_stack **stack_a);
void			exec_rb(t_stack **stack_b);
void			exec_rr(t_stack **stack_a, t_stack **stack_b);

void	exec_ra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	r(stack_a);
}

void	exec_rb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	r(stack_b);
}

void	exec_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
		return ;
	r(stack_a);
	r(stack_b);
}
