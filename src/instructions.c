/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:04:26 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/17 14:06:01 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

void	ft_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

int	swap_conditions(t_stack *stack)
{
	int	len;

	len = ft_stacksize(stack);
	if (len <= 1)
		return (0);
	return (1);
}

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
