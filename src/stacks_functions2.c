/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:05:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/26 14:56:45 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long		ft_stacksize(t_stack *stack);
t_stack		*ft_stacklast(t_stack **stack);

/* get stack last item */
t_stack	*ft_stacklast(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack))
		return (NULL);
	last = (*stack);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

/* return (long)stack_size */
long	ft_stacksize(t_stack *stack)
{
	long	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
/* map stack */
/* stack iter */
