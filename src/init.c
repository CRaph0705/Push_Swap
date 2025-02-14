/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/14 17:44:16 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			**init_program(int ac, char **av);
t_stack			*fill_stack(t_stack *stack, int *array, size_t len);

t_stack	**init_program(int ac, char **av)
{
	int		*formated_array;
	size_t	len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (!check_arg_valid(ac, av))
		return (error_handler(), NULL);
	len = get_array_len(parse(av, ' '));
	formated_array = format_arg(av);
	if (!formated_array)
		return (freetout(), error_handler(), NULL);
	if (check_dupes(formated_array, len) == 1)
		return (ft_printf("Dupe Exception > Error\n"), NULL);
	ft_printf("No dupe > Continue\n");
	// if no error continue
	// if (!stack_a || !stack_b)
	// 	return (ft_printf("stack missing"), free(formated_array), NULL);//free stack a or b depending on which one is missing
	// if (check_stack_errors(stacks))
		// return (freetout(), error_handler(), NULL);
	// *stack_b = *stacks[1];
	fill_stack(stack_a, formated_array, len);
	ft_printf("starts");
	(void)stack_b;
	return (NULL);
}

t_stack	*fill_stack(t_stack *stack, int *array, size_t len)
{
	t_stack		*new;
	size_t		i;

	i = 0;
	while (i < len)
	{
		new = ft_stacknew(&array[i]);
		if (!new)
			return (ft_stackclear(&stack, free), NULL);//freestack()
		ft_stackadd_back(&stack, new);
		i++;
	}
	return (stack);
}
// init function ->
// 1. parse
// 2. check if digit, valid items, dupes error, etc
// 3. init stacks
// 4. fills stack a with formated array
// 5. return un tableau de 2 structures ?