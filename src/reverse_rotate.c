/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:49:57 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 17:47:39 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_r(t_stack	**stack);
void	rra(t_stack **stack_a, int do_print);
void	rrb(t_stack **stack_b, int do_print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int do_print);

/* rr (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	r_r(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*forelast;
	size_t	len;

	if (!stack || !(*stack))
		return ;
	len = ft_stacksize((*stack));
	if (len < 2)
		return ;
	last = ft_stacklast(stack);
	forelast = *stack;
	while (forelast->next != last)
		forelast = forelast->next;
	ft_stackadd_front(stack, last);
	forelast->next = NULL;
	*stack = last;
	update_indices(stack);
	return ;
}

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rra(t_stack **stack_a, int do_print)
{
	if (!stack_a || !(*stack_a))
		return ;
	r_r(stack_a);
	if (do_print == 1)
		ft_putstr("rra\n");
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	rrb(t_stack **stack_b, int do_print)
{
	if (!stack_b || !(*stack_b))
		return ;
	r_r(stack_b);
	if (do_print == 1)
		ft_putstr("rrb\n");
}

/* rrr : rra and rrb at the same time. */
void	rrr(t_stack **stack_a, t_stack **stack_b, int do_print)
{
	if (!stack_a || !(*stack_a) || !stack_b || !(*stack_b))
		return ;
	r_r(stack_a);
	r_r(stack_b);
	if (do_print == 1)
		ft_putstr("rrr\n");
}
