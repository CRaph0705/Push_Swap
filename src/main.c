/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:41:18 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/07 17:43:24 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*stack_a;

	(void) ac, av;
	check_arg_valid(ac, av);
	//ignore av[0]
	//return if <2 déjà géré
	stack_a = ft_atoi(parse(av));
	// push_swap(stack_a);
	return (0);
}
