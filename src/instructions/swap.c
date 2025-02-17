/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:05:38 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/17 14:06:59 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		swap_conditions(t_stack *stack);
void	ft_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// int	swap_conditions(t_stack *stack)
// {
// 	int	len;

// 	len = ft_stacksize(stack);
// 	if (len <= 1)
// 		return (0);
// 	return (1);
// }

void	ft_swap(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	next = stack->next;
	if (stack == NULL || stack->next == NULL)
		return ;
	current->next = next->next;
	next->next = current;
	stack = next;
}

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
}
