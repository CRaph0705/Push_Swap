/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:15:31 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 17:48:18 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_b, t_stack **stack_a, int do_print);
void	pb(t_stack **stack_a, t_stack **stack_b, int do_print);

/* Take the first element at the top of src, and put it at the top of dest. */
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (!src || !(*src))
		return ;
	node = (*src);
	*src = (*src)->next;
	ft_stackadd_front(dest, node);
	update_indices(src);
	update_indices(dest);
}

/* pa (push a): 
Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	pa(t_stack **stack_b, t_stack **stack_a, int do_print)
{
	push(stack_b, stack_a);
	if (do_print == 1)
		ft_putstr("pa\n");
}

/* pb (push b): 
Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	pb(t_stack **stack_a, t_stack **stack_b, int do_print)
{
	push(stack_a, stack_b);
	if (do_print == 1)
		ft_putstr("pb\n");
}
