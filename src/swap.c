/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:05:38 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/17 15:39:46 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

// int		swap_conditions(t_stack *stack);
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// int	swap_conditions(t_stack *stack)
// {
// 	int	len;

// 	len = ft_stacksize(stack);
// 	if (len <= 1)
// 		return (0);
// 	return (1);
// }

void	ft_swap(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*stack = next;
	ft_putstr(">>>swap\n");
}

void	sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
}
