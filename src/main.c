/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:41:18 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 14:09:38 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (error_handler(), 0);
	stack_a = init_program(ac, av);
	if (!stack_a)
		return (error_handler(), 0);
	push_swap(stack_a, stack_b);
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	return (0);
}
//	./push_swap 11 2 0 111 34234 toto "123 1234 4321 321" "0101 1010 1243432"