/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/07 13:28:12 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list			**init_stacks(void);
t_list			*init_program(void);

//get stacks
// init stack a, b
// stack a = foreach (formated_array_item as item) -> new list item

t_list	**init_stacks(void)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	**stacks;

	stacks = malloc(sizeof(t_list *) * 2);
	if (!stacks)
		return (NULL);
	stack_a = ft_lstnew(NULL);
	stack_b = ft_lstnew(NULL);
	if (!stack_a || !stack_b)
		return (NULL, error_handler());
	stacks[0] = stack_a;
	stacks[1] = stack_b;
	return (stacks);
}

t_list	*init_program(void)
{
	t_list	**stacks;
	t_list	*stack_a;
	t_list	*stack_b;

	stacks = init_stacks();
	stack_a = stacks[0];
	stack_b = stacks[1];
	if (check_errors())
		return (freetout(), NULL);
	stack_a = fill_stack_a(stack_a);
	return (stacks);
}
// init function ->
// 1. parse
// 2. check if digit, valid items, dupes error, etc
// 3. init stacks
// 4. fills stack a with formated array
// 5. return un tableau de 2 structures ?