/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:48:21 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/21 13:33:14 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* r (rotate): Shift up all elements of stack by 1.
The first element becomes the last one. */
void	r(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	size_t	len;

	if (!stack || !(*stack))
		return ;
	head = (*stack);
	len = ft_stacksize(head);
	if (len < 2)
		return ;
	last = ft_stacklast(stack);
	*stack = head->next;
	last->next = head;
	head->next = NULL;
	update_indices(stack);
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	ra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	r(stack_a);
	ft_putstr("ra\n");
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	rb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	r(stack_b);
	ft_putstr("rb\n");
}

/* rr : ra and rb at the same time. */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
		return ;
	r(stack_a);
	r(stack_b);
	ft_putstr("rr\n");
}
