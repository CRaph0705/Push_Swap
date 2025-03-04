/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:29:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/04 20:09:11 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return (0);
	stack_a = init_program(ac, av);
	if (!stack_a)
		return (0);
	check(stack_a, stack_b);
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	return (0);
}
