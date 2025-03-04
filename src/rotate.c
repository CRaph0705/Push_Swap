/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:48:21 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 17:46:35 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack **stack);
void	ra(t_stack **stack_a, int do_print);
void	rb(t_stack **stack_b, int do_print);
void	rr(t_stack **stack_a, t_stack **stack_b, int do_print);

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
void	ra(t_stack **stack_a, int do_print)
{
	if (!stack_a || !(*stack_a))
		return ;
	r(stack_a);
	if (do_print == 1)
		ft_putstr("ra\n");
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	rb(t_stack **stack_b, int do_print)
{
	if (!stack_b || !(*stack_b))
		return ;
	r(stack_b);
	if (do_print == 1)
		ft_putstr("rb\n");
}

/* rr : ra and rb at the same time. */
void	rr(t_stack **stack_a, t_stack **stack_b, int do_print)
{
	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
		return ;
	r(stack_a);
	r(stack_b);
	if (do_print == 1)
		ft_putstr("rr\n");
}
