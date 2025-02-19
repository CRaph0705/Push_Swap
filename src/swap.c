/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:05:38 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/19 12:34:49 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* Swap the first 2 elements at the top of target stack. */
void	swap(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	next = current->next;
	ft_swap(&current->index, &next->index);
	current->next = next->next;
	next->next = current;
	*stack = next;
	update_indices(stack);
	ft_putstr(">>>swap\n");
}

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

/* ss : sa and sb at the same time. */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
