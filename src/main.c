/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:41:18 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/17 14:58:49 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	**stacks;
// int	*stack_a;
// check_arg_valid(ac, av);
//ignore av[0]
//return if <2 déjà géré
// stack_a = ft_atoi(parse(av));
// push_swap(stack_a);
// stacks = init_program(ac, av);
// char	**array;
// int		*int_array;
// int		i;
// i = 0;
int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = init_program(ac, av);
	display_stack(stack_a, 1);
	ft_swap(&stack_a);
	display_stack(stack_a, 1);
	free(stack_a);
	return (0);
}
	// while (i < ac)
	// {
	// 	printf("av[%d] = %s\n", i, av[i]);
	// 	i++;
	// }
	// i = 0;

	//format_arg()
/* 	array = parse(av, ' ');

	//
	int_array = format_arg(array);
	if (!int_array)
		return (printf("no int array Error\n"), 0);
	//
	while (array[i] != NULL)
	{
		printf("i = %d, array[i] = %s\n", i, array[i]);
		ft_printf("array[i] : %s\n", array[i]);
		i++;
	}
	i = 0; */
/* 	while (int_array[i])
	{
		ft_printf("main > int_array[%d] : %d\n", i, int_array[i]);
		i++;
	} */
	// (void)int_array;
