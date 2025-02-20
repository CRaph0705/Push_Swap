/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:16:22 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/20 21:26:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **stack_a, t_stack **stack_b);
// int		is_sorted(t_stack **stack);

/* ASC SORTED */
/* DESC SORTED */

// int	is_sorted(t_stack **stack)
// {
// 	if ( /* sorting logic here */)
// 		return (1);
// 	return (0);
// }

/*
tant que stack a est non vide :
	récupérer la min value de la current stack a.
	rotate jusqu'à avoir min value de a en haut de la stack a
	push min value de a dans b

tant que stack b est non vide :
	push b dans a

instant parano : ultime verif de target position == index pour chaque node
*/

// dans current stack, return le node dont target_pos == min
long	get_stack_min_target(t_stack **stack)
{
	t_stack	*cursor;
	long	min_target;

	if (!stack || !(*stack))
		return (ft_printf("!stack || !(*stack)"), -1);
	cursor = (*stack);
	min_target = cursor->target_pos;
	while (cursor != NULL)
	{
		if (cursor->target_pos < min_target)
		{
			min_target = cursor->target_pos;
		}
		cursor = cursor->next;
	}
	printf("DEBUG :: >>> min target : %li\n", min_target);
	return (min_target);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	long	min_target;

	while ((*stack_a) != NULL)
	{
		min_target = get_stack_min_target(stack_a);
		if (min_target == -1)
		{
			ft_printf("insertion_sort, error");
			return ;
		}
		while ((*stack_a)->target_pos != min_target)
		{
			ra(stack_a);
		}
		pb(stack_a, stack_b);
		display_stack(stack_a, 1);
	}

	// while (!(!(stack_b)))
	// {
	// 	pa(stack_b, stack_a);
	// }
	ft_printf("\ndisplay stack a : \n");
	display_stack(stack_a, 1);
	ft_printf("\ndisplay stack b : \n");
	display_stack(stack_b, 1);
	return ;
}
