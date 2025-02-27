/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:06 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/27 13:04:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b);

/* You have to write a program named push_swap 
that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order). */

/* The program must display the smallest list 
of instructions possible to sort the stack
a, the smallest number being at the top. */

/* • Instructions must be separated by a ’\n’ and nothing else. */
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	// insertion_sort(stack_a, stack_b);
	// insertion_sort(stack_a, stack_b);
	// smarter_sort(stack_a, stack_b);
	// if stack a size <= 5 do tiny_sort else do chunk sort
	chunk_sort(stack_a, stack_b);
	return ;
}

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