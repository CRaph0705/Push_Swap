/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:41:18 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/11 18:52:14 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	**stacks;
// int	*stack_a;
// check_arg_valid(ac, av);
//ignore av[0]
//return if <2 déjà géré
// stack_a = ft_atoi(parse(av));
// push_swap(stack_a);
// stacks = init_program(ac, av);
int	main(int ac, char **av)
{
	char	**array;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	av++;
	ac--;
	// while (i < ac)
	// {
	// 	printf("av[%d] = %s\n", i, av[i]);
	// 	i++;
	// }
	i = 0;
	array = parse(av, ' ');
	// while (array[i] != NULL)
	// {
	// 	printf("i = %d, array[i] = %s\n", i, array[i]);
	// 	ft_printf("array[i] : %s\n", array[i]);
	// 	i++;
	// }
	while (array[i])
	{
		ft_printf("parsed_array[j] : %s\n", array[i]);
		i++;
	}
	return (0);
}
