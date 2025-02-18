/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/18 20:09:14 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			**init_program(int ac, char **av);
t_stack			**fill_stack(t_stack **stack, int *array, size_t len);

/* 
rename this function : it initializes stack a and fills it
no stack b initialized here anymore
*/


// if no error continue
// if (!stack_a || !stack_b)
// 	return (ft_printf("stack missing"), free(formated_array), NULL);//free stack a or b depending on which one is missing
// if (check_stack_errors(stacks))
	// return (freetout(), error_handler(), NULL);
// *stack_b = *stacks[1];
t_stack	**init_program(int ac, char **av)
{
	int		*formated_array;
	size_t	len;
	t_stack	**stack_a;

	stack_a = NULL;
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return (error_handler(), ft_printf("no stack a"), NULL);
	if (!check_arg_valid(ac, av))
		return (error_handler(), ft_printf("init leave error"), NULL);
	av++;
	ac--;
	len = get_array_len(parse(av, ' '));
	formated_array = format_arg(av);
	if (!formated_array)
		return (freetout(), error_handler(), NULL);
	if (check_dupes(formated_array, len) == 1)
		return (ft_printf("Dupe Exception > Error\n"), NULL);
	ft_printf("No dupe > Continue\n");

	printf(">>> init program : formated array [0] = %i\n", formated_array[0]);
	printf(">>>init program : len = %zu\n", len);
	stack_a = fill_stack(stack_a, formated_array, len);
	ft_printf("starts\n");
	if (!stack_a)
		printf("oh oh probleme\n");
	return (stack_a);
}

t_stack	**fill_stack(t_stack **stack, int *array, size_t len)
{
	t_stack		*node;
	size_t		i;

	i = 0;
	while (i < len)
	{
		ft_printf(">>>fill_stack, début du while\n");
		node = ft_stacknew(array[i]);
		if (!node)
			return (ft_stackclear(stack), NULL);
		ft_printf(">>>fill_stack, continue\n");
		node->index = i;
		ft_stackadd_back(stack, node);
		i++;
	}
	ft_printf(">>>fill_stack : sortie de while ?\n");
	return (stack);
}
