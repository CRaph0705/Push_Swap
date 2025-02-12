/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/12 13:18:43 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list			**init_stacks(void);
t_list			**init_program(int ac, char **av);
t_list			*fill_stack(t_list *stack, int *array, size_t len);

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
	int		*formated_array;
	size_t	len;
	// t_list	*stack_a;
	// t_list	*stack_b;
	if (!check_arg_valid(ac, av))
		return (error_handler(), NULL);
	
	formated_array = format_arg(av);
	if (!formated_array)
		return (freetout(), error_handler(), NULL);
	//check formated array len
	// if no error continue
	stacks = init_stacks();
	if (check_stack_errors(stacks))
		return (freetout(), error_handler(), NULL);
	// *stack_a = *stacks[0];
	// *stack_b = *stacks[1];
	len = get_array_len(parse(av, ' '));
	stacks[0] = fill_stack(stacks[0], formated_array, len);
	return (stacks);
}

t_list	*fill_stack(t_list *stack, int *array, size_t len)
{
	t_list		*new;
	size_t		i;
	int			*content;

	i = 0;
	while (i < len)
	{
		content = ft_calloc(1, sizeof(int));
		if (!content)
			return (NULL);
		*content = array[i];
		new = ft_lstnew(content);
		if (!new)
			return (free(content), NULL);//freestacks()
		ft_lstadd_back(&stack, new);
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