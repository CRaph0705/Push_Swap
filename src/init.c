/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/05 12:02:07 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			**init_program(int ac, char **av);
t_stack			**fill_stack(t_stack **stack, int *array, size_t len);

/* if arg is valid return stack a
else return NULL 
*/
t_stack	**init_program(int ac, char **av)
{
	int		*formated_array;
	size_t	len;
	t_stack	**stack_a;

	stack_a = NULL;
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return (NULL);
	if (!check_arg_valid(ac, av))
		return (ft_stackclear(stack_a), NULL);
	av++;
	ac--;
	len = get_array_len(parse(av, ' '));
	formated_array = format_arg(av);
	if (!formated_array)
		return (ft_stackclear(stack_a), NULL);
	if (check_dupes(formated_array, len) == 1)
		return (ft_stackclear(stack_a), free(formated_array), NULL);
	stack_a = fill_stack(stack_a, formated_array, len);
	init_target_pos(stack_a, formated_array, len);
	free(formated_array);
	return (stack_a);
}

/* ft_stacknew foreach array[i] and stackadd_back each new node */
t_stack	**fill_stack(t_stack **stack, int *array, size_t len)
{
	t_stack		*node;
	size_t		i;

	i = 0;
	while (i < len)
	{
		node = ft_stacknew(array[i]);
		if (!node)
			return (ft_stackclear(stack), NULL);
		node->index = i;
		ft_stackadd_back(stack, node);
		i++;
	}
	return (stack);
}

void	init_target_pos(t_stack **stack, int *array, size_t len)
{
	t_stack	*current;
	long	pos;

	if (!stack || !(*stack))
		return ;
	pos = -1;
	current = (*stack);
	ft_sort_int_tab(array, len);
	while ((*stack) != NULL)
	{
		pos = get_num_index(current->value, array, len);
		if (pos == -1)
			return ;
		set_target_pos(current, pos);
		if (current->next == NULL)
			return ;
		current = current->next;
	}
}
