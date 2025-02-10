/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:41:18 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/10 16:17:09 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	// t_list	**stacks;
	// int	*stack_a;
	int	*array;
	int	i;

	i = 0;
	// check_arg_valid(ac, av);
	//ignore av[0]
	//return if <2 déjà géré
	// stack_a = ft_atoi(parse(av));
	// push_swap(stack_a);
	// stacks = init_program(ac, av);
	array = format_arg(parse(av));

	while (array[i] != '\0')
	{
		ft_printf("array[i] : %d", array[i]);
		i++;
	}
	return (0);
}
