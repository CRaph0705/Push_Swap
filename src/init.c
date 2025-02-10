/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/10 18:36:44 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list			**init_stacks(void);
t_list			**init_program(int ac, char **av);
t_list			*fill_stack(t_list *stack, char **array);
int				*cascade_atoi(const char **formated_array, int *dest);
int				atoi_dest(const char	*num_ptr, int *dest);

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
		return (freetout(), error_handler(), NULL);
	stacks[0] = stack_a;
	stacks[1] = stack_b;
	return (stacks);
}

t_list	**init_program(int ac, char **av)
{
	t_list	**stacks;
	t_list	*stack_a;
	t_list	*stack_b;
	int		*formated_array;

	if (!check_arg_valid(ac, av))
		return (error_handler(), NULL);
	formated_array = format_arg(av + 1);
	if (!formated_array)
		return (freetout(), error_handler(), NULL);
	//check formated array len
	// if no error continue
	stacks = init_stacks();
	*stack_a = *stacks[0];
	*stack_b = *stacks[1];
	if (check_stack_errors(stacks))
		return (freetout(), error_handler(), NULL);
	stack_a = fill_stack(stack_a, formated_array);
	return (stacks);
}

t_list	*fill_stack(t_list *stack, char **array)
{
	t_list	*new;
	int		i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			new = ft_lstnew(array[i]);
		ft_lstadd_back(stack, new);
		i++;
	}
}
// init function ->
// 1. parse
// 2. check if digit, valid items, dupes error, etc
// 3. init stacks
// 4. fills stack a with formated array
// 5. return un tableau de 2 structures ?