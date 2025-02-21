/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:06:37 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/21 11:07:22 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			insertion_sort(t_stack **stack_a, t_stack **stack_b);

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
	}
	while ((*stack_b) != NULL)
	{
		pa(stack_b, stack_a);
	}
	return ;
}
